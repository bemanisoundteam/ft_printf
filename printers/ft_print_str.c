/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:28:08 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/16 22:05:42 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

#include <libft.h>

#include <unistd.h>
#include <sys/types.h>

ssize_t	ft_print_str(char *s)
{
	return (write(1, s, ft_strlen(s)));
}
