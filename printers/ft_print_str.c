/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:28:08 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 19:04:14 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

#include <libft.h>

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

ssize_t	ft_print_str(char *s, int freestr)
{
	ssize_t	ret;

	if (!s)
		return (ft_print_str("(null)", FT_FALSE));
	ret = write(1, s, ft_strlen(s));
	if (freestr)
		free(s);
	return (ret);
}
