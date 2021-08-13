/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:33:24 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 11:52:23 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_swap *numbers, int stack)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = 0;
	while (i < numbers->limit_a && stack == 'a')
	{
		if (numbers->numbers_a[i] < numbers->numbers_a[smallest])
			smallest = i;
		i++;
	}
	while (i < numbers->limit_b && stack == 'b' && numbers->b_used)
	{
		if (numbers->numbers_b[i] < numbers->numbers_b[smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}

int	get_snd_smallest(t_swap *numbers, int stack)
{
	int	s_smallest;

	s_smallest = 0;
	if (stack == 'a')
		s_smallest = snd_small_a(numbers);
	else if (stack == 'b' && numbers->b_used == 1)
		s_smallest = snd_small_b(numbers);
	return (s_smallest);
}

int	get_biggest(t_swap *numbers, int stack)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = 0;
	while (i < numbers->limit_a && stack == 'a')
	{
		if (numbers->numbers_a[i] > numbers->numbers_a[biggest])
			biggest = i;
		i++;
	}
	while (i < numbers->limit_b && stack == 'b' && numbers->b_used)
	{
		if (numbers->numbers_b[i] > numbers->numbers_b[biggest])
			biggest = i;
		i++;
	}
	return (biggest);
}

int	get_sndbiggest(t_swap *numbers, int stack)
{
	int	s_biggest;

	s_biggest = 0;
	if (stack == 'a')
		snd_big_a(numbers);
	else if (stack == 'b' && numbers->b_used)
		snd_big_b(numbers);
	return (s_biggest);
}

int	check_order(t_swap *numbers)
{
	int	i;

	i = 1;
	numbers->smallest_a = get_smallest(numbers, 'a');
	numbers->snd_smallest_a = get_snd_smallest(numbers, 'a');
	numbers->biggest_a = get_biggest(numbers, 'a');
	numbers->snd_biggest_a = get_sndbiggest(numbers, 'a');
	if (numbers->limit_b > 1 && numbers->b_used != 0)
	{
		numbers->smallest_b = get_smallest(numbers, 'b');
		numbers->snd_smallest_b = get_snd_smallest(numbers, 'b');
		numbers->biggest_b = get_biggest(numbers, 'b');
		numbers->snd_biggest_b = get_sndbiggest(numbers, 'b');
	}
	while (i < numbers->limit_a)
	{
		if (numbers->numbers_a[i - 1] > numbers->numbers_a[i])
			return (1);
		i++;
	}
	if (numbers->b_used == 1)
		return (1);
	return (0);
}
