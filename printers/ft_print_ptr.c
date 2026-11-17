/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:29:54 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 16:37:51 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOW_HEX "0123456789abcdef"

#include "printers.h"

#include <unistd.h>
#include <sys/types.h>

ssize_t	ft_print_ptr(void *p)
{
	if (!p)
		return (ft_print_str("(nil)"));
	return (ft_print_base((uintptr_t) p, LOW_HEX, "0x"));
}
