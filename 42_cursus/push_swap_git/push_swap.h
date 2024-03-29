/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:10:37 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 15:15:00 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_CHUNK 20
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
typedef struct opcions_to_organize
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_order;

typedef struct push_swap
{
	int		*numbers_a;
	int		*numbers_b;
	int		hold_fst;
	int		hold_snd;
	int		biggest_a;
	int		snd_biggest_a;
	int		smallest_a;
	int		snd_smallest_a;
	int		chosen_one;
	int		biggest_b;
	int		snd_biggest_b;
	int		smallest_b;
	int		snd_smallest_b;
	int		argc;
	char	**argv;
	int		limit_a;
	int		limit_b;
	int		limit_chunk;
	int		chunk_control;
	int		b_used;
}	t_swap;

typedef struct aux
{
	int	index;
	int	index2;
	int	hold;
}	t_aux;

int		check_b_stack(t_swap *numbers, int index, t_order *to_do);
int		check_error(t_swap numbers);
int		check_order(t_swap *numbers);
void	check_size_stack(t_swap *numbers, t_order *to_do);
int		check_todo(t_order *to_do, t_swap *numbers);
void	chunk_maker_aux(t_swap *numbers, int *hold_snd,
			int *hold_fst, int *chunk);
void	exec_order(t_swap *numbers, t_order *to_do, int index,
			int index_b);			
void	exec_pp(t_swap *number, int stack);
void	exec_ra(t_swap *number, int *hold, int limite);
void	exec_rb(t_swap *number, int *hold, int limite);
void	exec_rr(t_swap *number, int stack, int limite);
void	exec_rra(t_swap *number, int *hold, int limite);
void	exec_rrb(t_swap *number, int *hold, int limite);
void	exec_rrr(t_swap *number, int stack, int limite);
void	exec_ss(t_swap *number, int stack);
void	exec_todo(t_swap *numbers, t_order *to_do);
void	ft_putchar(char c);
void	ft_print_todo(t_swap *numbers, t_order to_do);
int		ft_putstr(const char *s);
int		get_biggest(t_swap *numbers, int stack);
int		*get_chunk(t_swap *numbers);
int		get_first_p(t_swap *numbers, int *chunk);
int		get_posicion(int iten1, int total_arg);
int		get_smallest(t_swap *numbers, int stack);
int		medium_sort(t_swap *numbers, t_order *to_do);
void	more_than_three(t_swap *numbers, t_order *to_do);
void	move_chunk(int *chunk, t_swap *numbers, t_order *to_do);
void	normalize(t_order *to_do, int stack);
int		order(t_order to_do);
int		pp_case1(t_swap *number, int stack);
void	printa_dpsTira(t_swap *numbers);
void	print_sa(t_swap *numbers);
void	print_sb(t_swap *numbers);
void	print_ss(t_swap *numbers);
void	print_pa(t_swap *numbers);
void	print_pb(t_swap *numbers);
void	print_ra(t_swap *numbers);
void	print_rb(t_swap *numbers);
void	print_rr(t_swap *numbers);
void	print_rra(t_swap *numbers);
void	print_rrb(t_swap *numbers);
void	print_rrr(t_swap *numbers);
int		right_place(t_swap *numbers, int value, t_order *to_do);
int		small_sort(t_swap *numbers, t_order *to_do);
int		snd_big_a(t_swap *numbers);
int		snd_big_b(t_swap *numbers);
int		snd_small_a(t_swap *numbers);
int		snd_small_b(t_swap *numbers);
void	three_or_less(t_swap *numbers, t_order *to_do);
void	up_or_down(int iten1, int total_arg, t_order *to_do);
int		up_or_down_b(int iten1, int total_arg, t_order *to_do, t_swap *numbers);
#endif
