/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:31:08 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/16 13:29:35 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H
# ifndef ULLONG
#	define ULLONG unsigned long long int
#	endif
# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_unsigned_itoa(unsigned int n);
void	ft_print_hex(char letter, unsigned long long int nmb);
#endif