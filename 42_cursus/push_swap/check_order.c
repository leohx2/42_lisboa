/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:33:24 by lrosendo          #+#    #+#             */
/*   Updated: 2021/06/15 09:33:35 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_swap *numbers, int stack)
{
	int i;
	int smallest;

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
	int i;
	int s_smallest;

	i = 0;
	s_smallest = 0;
	if (stack == 'a')
	{
		if (numbers->smallest_a == 0)
			s_smallest = 1;
		while (i < numbers->limit_a)
		{
			if (numbers->numbers_a[i] < numbers->numbers_a[s_smallest]
				&& (i != numbers->smallest_a))
				s_smallest = i;
			i++;
		}
	}
	else if (stack == 'b' && numbers->b_used == 1)
	{
		if (numbers->smallest_b == 0)
			s_smallest = 1;
		while (i < numbers->limit_b)
		{
			if (numbers->numbers_b[i] < numbers->numbers_b[s_smallest]
				&& (i != numbers->smallest_b))
				s_smallest = i;
			i++;
		}
	}
	return (s_smallest);
}

int	get_biggest(t_swap *numbers, int stack)
{
	int i;
	int biggest;

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
	int i;
	int s_biggest;

	i = 0;
	s_biggest = 0;
	if (stack == 'a')
	{
		if (numbers->biggest_a == 0)
			s_biggest = 1;
		while (i < numbers->limit_a)
		{
			if (numbers->numbers_a[i] > numbers->numbers_a[s_biggest]
				&& (i != numbers->biggest_a))
				s_biggest = i;
			i++;
		}
	}
	else if (stack == 'b' && numbers->b_used)
	{
		if (numbers->biggest_b == 0)
			s_biggest = 1;
		while (i < numbers->limit_b)
		{
			if (numbers->numbers_b[i] > numbers->numbers_b[s_biggest]
				&& (i != numbers->biggest_b))
				s_biggest = i;
			i++;
		}
	}
	return (s_biggest);
}

int	check_order(t_swap *numbers)//por agora verifica somente a ordem do stack A
{
	int	i;

	i = 1;
	//------------A---------//
	numbers->smallest_a = get_smallest(numbers, 'a');
	numbers->snd_smallest_a = get_snd_smallest(numbers, 'a');
	numbers->biggest_a = get_biggest(numbers, 'a');
	numbers->snd_biggest_a = get_sndbiggest(numbers, 'a');
	//------------B---------//
	if (numbers->limit_b > 1 && numbers->b_used != 0)
	{
		numbers->smallest_b = get_smallest(numbers, 'b');
		numbers->snd_smallest_b = get_snd_smallest(numbers, 'b');
		numbers->biggest_b = get_biggest(numbers, 'b');
		numbers->snd_biggest_b = get_sndbiggest(numbers, 'b');
	}
	//------------order---------//
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
