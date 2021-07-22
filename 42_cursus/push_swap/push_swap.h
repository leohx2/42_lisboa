/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:10:37 by lrosendo          #+#    #+#             */
/*   Updated: 2021/07/22 09:02:31 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# define MAX_CHUNK 20
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
	int hold_fst;
	int hold_snd;
	int biggest_a;//to get the posicion only
	int snd_biggest_a;//to get the posicion only
	int smallest_a;//to get the posicion only
	int snd_smallest_a;//to get the posicion only
	int	chosen_one;//the index that I need to pass to STACK B
	int biggest_b;
	int snd_biggest_b;
	int smallest_b;
	int snd_smallest_b;
	int	argc;
	char **argv;
	int	limit_a;
	int	limit_b;
	int	limit_chunk;
	int	b_used;
}	t_swap;

void	check_error(t_swap numbers);
int		check_order(t_swap *numbers);
void	check_size_stack(t_swap *numbers, t_order *to_do);
void	check_todo(t_order *to_do);
void	exec_pp(t_swap *number, int stack);
void	exec_rr(t_swap *number, int stack, int limite);
void	exec_rrr(t_swap *number, int stack, int limite);
void	exec_ss(t_swap *number, int stack);
void	exec_todo(t_swap *numbers, t_order *to_do);
void	ft_putchar(char c);
void	ft_print_todo(t_swap *numbers, t_order to_do);
int		ft_putstr(const char *s);
int		get_biggest(t_swap *numbers, int stack);
int		*get_chunk(t_swap *numbers);
int		get_posicion(int iten1, int total_arg);
int		get_smallest(t_swap *numbers, int stack);
int		medium_sort(t_swap *numbers, t_order *to_do);
void	more_than_three(t_swap *numbers, t_order *to_do);
void	move_chunk(int *chunk, t_swap *numbers, t_order *to_do);
void	normalize(t_order *to_do);
int		pp_case1(t_swap *number, int stack);
void	printa_dpsTira(t_swap *numbers);
int		small_sort(t_swap *numbers, t_order *to_do);
void	three_or_less(t_swap *numbers, t_order *to_do);
void	up_or_down(int iten1, int total_arg, t_order *to_do);
#endif
