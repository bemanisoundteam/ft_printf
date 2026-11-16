/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformatted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:27:07 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/16 23:13:47 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DECIMAL "0123456789"
#define LOW_HEX "0123456789abcdef"
#define HIGH_HEX "0123456789ABCDEF"

#include "ft_printf.h"
#include "printers/printers.h"

#include <libft.h>

#include <stdarg.h>

int	ft_print_formatted(char format, va_list *args)
{
	if (format == 'c')
		return (ft_print_chr(va_arg(*args, int)));
	if (format == 's')
		return (ft_print_str( va_arg(*args, char *)));
	if (format == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_print_base(va_arg(*args, int), DECIMAL));
	if (format == 'u')
		return (ft_print_base(va_arg(*args, unsigned int), DECIMAL));
	if (format == 'x')
		return (ft_print_base(va_arg(*args, int), LOW_HEX));
	if (format == 'X')
		return (ft_print_base(va_arg(*args, int), HIGH_HEX));
	if (format == '%')
		return (ft_print_chr('%'));
	return (-1);
}
