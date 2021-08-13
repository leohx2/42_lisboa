/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:05:19 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 14:15:05 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_numbers(t_swap *numbers)
{
	int	i;

	i = 1;
	numbers->numbers_a = (int *)ft_calloc(sizeof(int), numbers->argc);
	numbers->numbers_b = (int *)ft_calloc(sizeof(int), numbers->argc);
	while (i < numbers->argc)
	{
		numbers->numbers_a[i - 1] = ft_atoi(numbers->argv[i]);
		i++;
	}
}

void	normalize(t_order *to_do, int stack)
{
	if (stack == 'A')
	{
		to_do->sa = 0;
		to_do->sb = 0;
		to_do->ss = 0;
		to_do->pa = 0;
		to_do->pb = 0;
		to_do->ra = 0;
		to_do->rb = 0;
		to_do->rr = 0;
		to_do->rra = 0;
		to_do->rrb = 0;
		to_do->rrr = 0;
	}
	else
	{
		to_do->sa = 0;
		to_do->pb = 0;
		to_do->ra = 0;
		to_do->rra = 0;
	}
}

void	loop_ordering(t_swap *numbers)
{
	t_order	to_do;

	numbers->limit_a = numbers->argc - 1;
	numbers->limit_b = 0;
	numbers->b_used = 0;
	numbers->chunk_control = 0;
	while (check_order(numbers))
	{
		if (numbers->argc > 4)
			more_than_three(numbers, &to_do);
		else
			three_or_less(numbers, &to_do);
	}
}

void	ft_print_todo(t_swap *numbers, t_order to_do)
{
	if (to_do.sa == 1)
		print_sa(numbers);
	if (to_do.sb == 1)
		print_sb(numbers);
	if (to_do.ss == 1)
		print_ss(numbers);
	if (to_do.pa == 1)
		print_pa(numbers);
	if (to_do.pb == 1)
		print_pb(numbers);
	if (to_do.ra == 1)
		print_ra(numbers);
	if (to_do.rb == 1)
		print_rb(numbers);
	if (to_do.rr == 1)
		print_rr(numbers);
	if (to_do.rra == 1)
		print_rra(numbers);
	if (to_do.rrb == 1)
		print_rrb(numbers);
	if (to_do.rrr == 1)
		print_rrr(numbers);
}

int	main(int argc, char **argv)
{
	t_swap	numbers;
	int		i;

	i = 0;
	numbers.argc = argc;
	numbers.argv = argv;
	check_error(numbers);
	get_numbers(&numbers);
	loop_ordering(&numbers);
	free(numbers.numbers_a);
	free(numbers.numbers_b);
	exit(EXIT_SUCCESS);
}
