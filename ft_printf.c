/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:04:10 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 18:23:34 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FORMAT_SPECIFIERS "cspdiuxX%"

#include "ft_printf.h"

#include <libft.h>

#include <unistd.h>
#include <stdarg.h>

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
