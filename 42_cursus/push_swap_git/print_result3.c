/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:04:01 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 15:12:20 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rrr(t_swap *numbers)
{
	exec_rrr(numbers, 'a', numbers->limit_a);
	exec_rrr(numbers, 'b', numbers->limit_b);
	ft_putstr("rrr\n");
}

void	move_chunk(int *chunk, t_swap *numbers, t_order *to_do)
{
	int	index;

	index = get_first_p(numbers, chunk);
	up_or_down(index, numbers->limit_a, to_do);
	check_b_stack(numbers, index, to_do);
}

void	chunk_maker_aux(t_swap *numbers, int *hold_snd, int *hold_fst,
		int *chunk)
{
	int	index;
	int	limit;

	limit = 1;
	while (limit < (numbers->limit_a - 3) && limit < MAX_CHUNK)
	{
		index = 0;
		while (index < numbers->limit_a)
		{
			if (numbers->numbers_a[index] > *hold_snd
				&& numbers->numbers_a[index] < *hold_fst)
				*hold_fst = numbers->numbers_a[index];
			index++;
		}
		*hold_snd = *hold_fst;
		*hold_fst = numbers->numbers_a[get_biggest(numbers, 'a')];
		chunk[limit] = *hold_snd;
		limit++;
	}
	index = 0;
	numbers->limit_chunk = limit;
}
