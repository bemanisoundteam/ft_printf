/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 20:41:23 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 19:05:15 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

#include <libft.h>

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

static size_t	calc_nbr_len(uintmax_t n, size_t base_len)
{
	size_t	ret;

	ret = 1;
	while (n >= base_len)
	{
		ret++;
		n /= base_len;
	}
	return (ret + 1);
}

ssize_t	ft_print_base(uintmax_t nbr, const char *base, const char *prefix)
{
	char	*str;
	size_t	size;
	size_t	base_len;
	size_t	prefix_len;

	base_len = ft_strlen(base);
	prefix_len = ft_strlen(prefix);
	size = calc_nbr_len(nbr, base_len) + prefix_len;
	str = malloc(size);
	if (!str)
		return (-1);
	ft_memcpy(str, prefix, prefix_len);
	str[--size] = '\0';
	while (nbr >= base_len)
	{
		str[--size] = base[nbr % base_len];
		nbr /= base_len;
	}
	str[--size] = base[nbr];
	return (ft_print_str(str, FT_TRUE));
}
