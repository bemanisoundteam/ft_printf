/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:04:10 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/16 23:13:08 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FORMAT_SPECIFIERS "cspdiuxX%"

#include "ft_printf.h"

#include <libft.h>

#include <unistd.h>
#include <stdarg.h>

static ssize_t	ft_printspan(const char **s, const char *set)
{
	size_t	span;
	ssize_t	result;

	span = ft_strcspn(*s, set);
	result = write(1, *s, span);
	if (result == -1)
		return (-1);
	*s += span;
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		written;
	ssize_t	result;

	va_start(args, format);
	written = 0;
	while (*format)
	{
		if (*format != '%')
		{
			result = ft_printspan(&format, "%");
			written += result;
			continue ;
		}
		if (!ft_strchr(FORMAT_SPECIFIERS, *++format))
			result = write(1, format - 1, 2);
		else
			result = ft_print_formatted(*format++, &args);
		if (result == -1)
			return (-1);
		written += result + 1;
	}
	va_end(args);
	return (written);
}
