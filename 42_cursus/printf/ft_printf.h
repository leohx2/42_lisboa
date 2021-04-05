/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:31:08 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/05 18:53:59 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H
# ifndef ULLONG
#	define ULLONG unsigned long int
# endif
# ifndef TEST
#	define TEST unsigned int
# endif
# include "libft/libft.h"
# include <stdarg.h>

char	*ft_return_type(char *buffer, int *i_main, va_list *list);
int		ft_printf(const char *format, ...);
char	*ft_unsigned_itoa(unsigned int n);
char	*ft_print_hex(char letter, TEST nmb);
char	*ft_print_memory(ULLONG nmb);
int		ft_printf_flags(int *index, char *buffer, va_list *list);
int		ft_is_in_set(char c, char *set);
int 	ft_is_last(char *set, int choice);
int 	ft_set_flag(char *set, int *index, va_list *list, char *buffer, 
			int *i_main, int flag);
int 	ft_set_digit(int index2, char *nmbr_int, char *str, char *buffer, 
			int *index,	int *i_main, char *set);
int		ft_final_step(char *set, va_list *list, int *i_main, char *buffer);
int		ft_help_dot(char *str, char *buffer, int i_main, int *helper,
			int *nmbr_int);
int		ft_putstr(const char *s);
int		ft_putchar(char c);
int		ft_rm_diff(int index2, char *nmbr_int1, char *str, char *buffer,
		int *index, int *i_main, char *set, int *confirm);
int		ft_set_minus(int index2, char *str, char *buffer, int *i_main, int D);
int		ft_set_zd(char *set, int index2, char *str, char *buffer, int *i_main, int f);
int		ft_replacing(char *buffer, va_list list, int *i_main);
int		ft_is_null(char *set, char *str);
int 	ft_dontprint(char *set, char *str, char *buffer, int i_main);
int		ft_index2(char *buffer, int i_main, char *str, char *n1, char *n2);
void	ft_index1(char *set, int *index, int flag, char *nmbr_a);
#endif
