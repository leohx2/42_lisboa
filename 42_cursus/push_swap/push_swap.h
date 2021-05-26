/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:10:37 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/26 11:06:23 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct opcions_to_organize
{
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int	ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	
} t_order;


typedef struct push_swap
{
	int *numbers_a;
	int	*numbers_b;
	int biggest_a;//to get the posicion only
	int snd_biggest_a;//to get the posicion only
	int smallest_a;//to get the posicion only
	int snd_smallest_a;//to get the posicion only
	//int biggest_b;
	//int fst_smallest_b;
	//int snd_smallest_b;
	int	argc;
	char **argv;
	int	limit_a;
	int	limit_b;
}	t_swap;


void	ft_putchar(char c);
int		ft_putstr(const char *s);
void	check_error(t_swap numbers);
int		check_order(t_swap *numbers);
int		order_a(t_swap *numbers, int size, t_order *to_do);
void	ft_print_todo(t_swap *numbers, t_order to_do);
void	exec_todo(t_swap *numbers, t_order *to_do);
void	exec_sa(t_swap *number);
void	exec_ra(t_swap *number);
void	exec_rra(t_swap *number);
void	exec_pb(t_swap *number);
int		pb_case1(t_swap *number);

#endif
