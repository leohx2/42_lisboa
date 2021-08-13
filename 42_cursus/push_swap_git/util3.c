/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:18:57 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 15:10:19 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_or_down(int iten1, int total_arg, t_order *to_do)
{
	if (iten1 == 0)
		to_do->pb = 1;
	else if (total_arg % 2 == 0)
	{
		if (iten1 <= total_arg / 2 )
			to_do->ra = 1;
		else if (iten1 > total_arg / 2)
			to_do->rra = 1;
	}
	else if (total_arg % 2 == 1)
	{
		if (iten1 <= total_arg / 2 + 1)
			to_do->ra = 1;
		else if (iten1 > total_arg / 2 + 1)
			to_do->rra = 1;
	}
}

int	up_or_down_b(int iten1, int total_arg, t_order *to_do, t_swap *numbers)
{
	if (iten1 == 0 || to_do->sb)
		return (0);
	else if (total_arg % 2 == 0)
	{
		if (iten1 <= total_arg / 2)
			to_do->rb = 1;
		else if (iten1 > total_arg / 2)
			to_do->rrb = 1;
		else
			return (0);
	}
	else if (total_arg % 2 == 1)
	{
		if (iten1 <= total_arg / 2 + 1)
			to_do->rb = 1;
		else if (iten1 > total_arg / 2 + 1)
			to_do->rrb = 1;
		else
			return (0);
	}
	return (1);
}

int	check_b_stack(t_swap *numbers, int index, t_order *to_do)
{
	int	index_b;
	int	hold;
	int	test;

	test = 0;
	hold = 0;
	index_b = 0;
	while (index_b < numbers->limit_b)
	{
		if (numbers->numbers_b[index_b] > numbers->numbers_a[index])
			hold = index_b;
		index_b++;
	}
	if (order(*to_do))
		exec_order(numbers, to_do, index, index_b);
	return (1);
}

void	exec_order(t_swap *numbers, t_order *to_do, int index, int index_b)
{
	if (numbers->numbers_a[index]
		> numbers->numbers_b[get_biggest(numbers, 'b')]
		|| numbers->numbers_a[index]
		< numbers->numbers_b[get_smallest(numbers, 'b')])
	{
		if (up_or_down_b(get_biggest(numbers, 'b')
				, index_b, to_do, numbers))
			if (check_todo(to_do, numbers) == 1)
				normalize(to_do, 'a');
	}
	else if (up_or_down_b(right_place(numbers,
				numbers->numbers_a[index], to_do), numbers->limit_b
			, to_do, numbers))
		if (check_todo(to_do, numbers) == 1)
			normalize(to_do, 'a');
}

int	right_place(t_swap *numbers, int value, t_order *to_do)
{
	int	i;
	int	hold1;
	int	hold2;

	i = 0;
	hold1 = -1;
	hold2 = -1;
	while (i < numbers->limit_b)
	{
		if (value > numbers->numbers_b[i] && hold1 == -1)
			hold1 = i;
		else if (value > numbers->numbers_b[i])
			hold2 = i;
		if (numbers->numbers_b[hold2] > numbers->numbers_b[hold1])
			hold1 = hold2;
		i++;
	}
	if (hold1 == -1)
		return (0);
	return (hold1);
}
