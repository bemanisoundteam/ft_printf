/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabanne <ccabanne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:24:42 by ccabanne          #+#    #+#             */
/*   Updated: 2026/11/17 16:55:49 by ccabanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include <stdint.h>
# include <sys/types.h>

ssize_t	ft_print_chr(char c);
ssize_t	ft_print_str(char *s);
ssize_t	ft_print_ptr(void *p);
ssize_t	ft_print_base(uintmax_t nbr, const char *base, const char *prefix);
ssize_t	ft_print_signed(intmax_t nbr, const char *base);

#endif
