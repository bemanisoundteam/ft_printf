/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformatted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:27:07 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 19:57:22 by ccabanne         ###   ########.fr       */
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
