/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:26:25 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/16 19:38:33 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

#include <unistd.h>
#include <sys/types.h>

ssize_t	ft_print_chr(char c)
{
	return (write(1, &c, 1));
}
