/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:52:33 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 16:52:34 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

ssize_t	ft_print_signed(intmax_t nbr, const char *base)
{
	if (nbr < 0)
		return (ft_print_base(nbr * -1, base, "-"));
	return (ft_print_base(nbr, base, ""));
}
