/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 20:41:23 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 15:57:37 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

#include <libft.h>

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

static size_t	calc_nbr_len(intmax_t n, int base_len)
{
	size_t	ret;

	ret = 1;
	if (n < 0)
		ret++;
	else
		n *= -1;
	while (n <= -(base_len))
	{
		ret++;
		n /= base_len;
	}
	return (ret + 1);
}

ssize_t	ft_print_base(intmax_t nbr, const char *base)
{
	char	*str;
	size_t	size;
	int		base_len;
	ssize_t	ret;

	base_len = ft_strlen(base);
	size = calc_nbr_len(nbr, base_len);
	str = malloc(size);
	if (!str)
		return (-1);
	str[--size] = '\0';
	if (nbr < 0)
		str[0] = '-';
	else
		nbr *= -1;
	while (nbr <= -base_len)
	{
		str[--size] = base[-(nbr % base_len)];
		nbr /= base_len;
	}
	str[--size] = base[-nbr];
	ret = ft_print_str(str);
	free(str);
	return (ret);
}
