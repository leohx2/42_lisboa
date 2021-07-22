/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sizes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:15:51 by lrosendo          #+#    #+#             */
/*   Updated: 2021/07/22 09:04:09 by lrosendo         ###   ########.fr       */
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
		if (numbers->numbers_b[0] < numbers->numbers_b[1])
			to_do->sb = 1;
	}
	else
		to_do->pa = 1;
}

int		small_sort(t_swap *numbers, t_order *to_do)
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
