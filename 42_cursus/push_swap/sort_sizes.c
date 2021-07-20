/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sizes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:15:51 by lrosendo          #+#    #+#             */
/*   Updated: 2021/07/06 11:33:13 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_size_stack(t_swap *numbers, t_order *to_do)
{
	if (numbers->argc <= 4)
		small_sort(numbers, to_do);
	else if (numbers->argc <= 6)
		medium_sort(numbers, to_do);
}

// to sort until 3 numbers.
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

// to sort from 4 to 5 integers, sending the first 2 itens to stack b and using the small_sort funct, after it 
int	medium_sort(t_swap *numbers, t_order *to_do)
{
	static int	control;
	//printf("LIMITE A %d, SMALL %d, BIGG %d\n", numbers->limit_a, numbers->smallest_a, numbers->biggest_a);
	if (numbers->smallest_a != 0 && numbers->limit_a > 3)
	{
		if (numbers->smallest_a == 1)
			to_do->sa = 1;
		else if (numbers->smallest_a <= 3)
			to_do->ra = 1;
		else if (numbers->smallest_a > 3)
			to_do->rra = 1;
		if (to_do->sa == 1 && numbers->numbers_a[2] > numbers->numbers_a[3] && control < 2)
		{
			control++;
			to_do->sa = 0;
			to_do->pb = 1;
		}
	}
	else if (numbers->smallest_a == 0 && numbers->limit_a > 3 && control < 2)//sending the first and scnd itens from stack A to stack B
	{
		control++;
		to_do->pb = 1;
		return (0);
	}
	else if (numbers->limit_a == 3)
	{
		if (small_sort(numbers, to_do))
			to_do->pa = 1;
		if (numbers->numbers_b[0] < numbers->numbers_b[1])
			to_do->sb = 1;
	}
	else
		to_do->pa = 1;
	return (0);
}

