/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:04:10 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 21:11:39 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FORMAT_SPECIFIERS "cspdiuxX%"

#define DECIMAL "0123456789"
#define LOW_HEX "0123456789abcdef"
#define HIGH_HEX "0123456789ABCDEF"

#include "ft_printf.h"

#include <libft.h>

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

static ssize_t	ft_print_chr(char c)
{
	return (write(1, &c, 1));
}

static ssize_t	ft_print_str(char *s, int freestr)
{
	ssize_t	ret;

	if (!s)
		return (ft_print_str("(null)", FT_FALSE));
	ret = write(1, s, ft_strlen(s));
	if (freestr)
		free(s);
	return (ret);
}

static	ssize_t	ft_print_ptr(void *p)
{
	if (!p)
		return (ft_print_str("(nil)", FT_FALSE));
	return (ft_print_str(ft_uimtoa_base(
				(uintptr_t) p, LOW_HEX, "0x"), FT_TRUE));
}

static int	ft_print_formatted(char format, va_list *args)
{
	if (format == 'c')
		return (ft_print_chr(va_arg(*args, int)));
	if (format == 's')
		return (ft_print_str(va_arg(*args, char *), FT_FALSE));
	if (format == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_print_str(ft_itoa(va_arg(*args, int)), FT_TRUE));
	if (format == 'u')
		return (ft_print_str(ft_uimtoa_base(
					va_arg(*args, unsigned int), DECIMAL, ""), FT_TRUE));
	if (format == 'x')
		return (ft_print_str(ft_uimtoa_base(
					va_arg(*args, unsigned int), LOW_HEX, ""), FT_TRUE));
	if (format == 'X')
		return (ft_print_str(ft_uimtoa_base(
					va_arg(*args, unsigned int), HIGH_HEX, ""), FT_TRUE));
	if (format == '%')
		return (ft_print_chr('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		written;
	size_t	span;
	ssize_t	result;

	va_start(args, format);
	written = 0;
	while (*format)
	{
		if (*format != '%')
		{
			span = ft_strcspn(format, "%");
			result = write(1, format, span);
			format += span;
		}
		else if (!ft_strchr(FORMAT_SPECIFIERS, *++format))
			result = write(1, format++ - 1, 2);
		else
			result = ft_print_formatted(*format++, &args);
		if (result == -1)
			return (-1);
		written += result;
	}
	va_end(args);
	return (written);
}
