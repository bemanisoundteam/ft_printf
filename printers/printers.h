/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:24:42 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 20:45:06 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include <stdint.h>
# include <sys/types.h>

ssize_t	ft_print_chr(char c);
ssize_t	ft_print_str(char *s, int freestr);
ssize_t	ft_print_ptr(void *p);

#endif
