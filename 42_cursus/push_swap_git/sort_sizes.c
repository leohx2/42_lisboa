/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sizes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:15:51 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 12:06:20 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_size_stack(t_swap *numbers, t_order *to_do)
{
	if (numbers->argc <= 4)
		small_sort(numbers, to_do);
	else if (numbers->limit_a == 3)
	{
		if (small_sort(numbers, to_do))
			to_do->pa = 1;
		if (numbers->numbers_b[0] < numbers->numbers_b[1] && !order(*to_do))
			to_do->sb = 1;
	}
	else
		to_do->pa = 1;
}

int	small_sort(t_swap *numbers, t_order *to_do)
{
	if (numbers->limit_a > 3)
		return (1);
	if ((numbers->smallest_a == 1 && numbers->biggest_a == 2)
		|| (numbers->smallest_a == 0 && numbers->biggest_a == 1)
		|| (numbers->smallest_a == 2 && numbers->biggest_a == 0))
		to_do->sa = 1;
	else if (numbers->smallest_a == 1 && numbers->biggest_a == 0)
		to_do->ra = 1;
	else if (numbers->smallest_a == 2 && numbers->biggest_a == 1)
		to_do->rra = 1;
	else
		return (1);
	return (0);
}

int	order(t_order to_do)
{
	if (to_do.sa == 1
		|| to_do.sb == 1
		|| to_do.ss == 1
		|| to_do.pa == 1
		|| to_do.pb == 1
		|| to_do.ra == 1
		|| to_do.rb == 1
		|| to_do.rr == 1
		|| to_do.rra == 1
		|| to_do.rrb == 1
		|| to_do.rrr == 1)
		return (1);
	else
		return (0);
}

void	more_than_three(t_swap *numbers, t_order *to_do)
{
	int	*chunk;

	chunk = get_chunk(numbers);
	while (numbers->limit_a > 3)
	{
		if (numbers->chunk_control >= 20)
		{
			numbers->chunk_control = 0;
			free(chunk);
			chunk = get_chunk(numbers);
		}
		normalize(to_do, 'A');
		move_chunk(chunk, numbers, to_do);
		check_todo(to_do, numbers);
		ft_print_todo(numbers, *to_do);
	}
	free(chunk);
	three_or_less(numbers, to_do);
}

void	three_or_less(t_swap *numbers, t_order *to_do)
{
	int	safe;

	while (check_order(numbers))
	{
		normalize(to_do, 'A');
		check_size_stack(numbers, to_do);
		check_todo(to_do, numbers);
		ft_print_todo(numbers, *to_do);
	}
}
