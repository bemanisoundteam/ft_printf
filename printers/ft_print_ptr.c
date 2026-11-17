/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:29:54 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 16:09:58 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOW_HEX "0123456789abcdef"

#include "printers.h"

#include <unistd.h>
#include <sys/types.h>

ssize_t	ft_print_ptr(void *p)
{
	ssize_t	a;
	ssize_t	b;

	if (!p)
		return (ft_print_str("(nil)"));
	a = ft_print_str("0x");
	if (a == -1)
		return (-1);
	b = ft_print_base((intptr_t) p, LOW_HEX);
	if (b == -1)
		return (-1);
	return (a + b);
}
