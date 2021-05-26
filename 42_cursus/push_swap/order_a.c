/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:33:17 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/26 11:18:01 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_a(t_swap *numbers, int size, t_order *to_do)
{
	//printf("SIZE -> %d\tBIGGER %d\tSND_BIGGER %d \tSMALLER %d\tSND_SMALLER %d\n",
	//size, numbers->biggest_a, numbers->snd_biggest_a, numbers->smallest_a, numbers->snd_smallest_a);
	//---------CONFIG SA---------//
	if (size == 2)
		to_do->sa = 1;
	else if (numbers->smallest_a == 1 && numbers->snd_smallest_a != 0)
	{
		if (numbers->smallest_a == 1 && numbers->snd_smallest_a != 2)
			to_do->sa = 1;
		else if (size == 3)
			to_do->sa = 1;
	}
	else if (numbers->smallest_a == 0 && numbers->biggest_a == 1
		&& numbers->snd_smallest_a == 2)
		to_do->sa = 1;
	else if (numbers->biggest_a == 0 && numbers->snd_biggest_a == 1)
		to_do->sa = 1;
	else if (numbers->smallest_a == 1 && numbers->snd_smallest_a == 0 && !pb_case1(numbers))
		to_do->sa = 1;
	//------CONFIG PB--------//
	if (numbers->smallest_a == 0 && to_do->sa == 0
		|| (numbers->smallest_a == 1 && numbers->snd_smallest_a == 0) && to_do->sa == 0)
		to_do->pb = 1;
	else if (numbers->snd_biggest_a == 0 && numbers->smallest_a == 1 && pb_case1(numbers))
		to_do->pb = 1;
	//--------CONFIG RA--------//
	else if (numbers->smallest_a != 0 && ((size % 2 == 1) && numbers->smallest_a < size/2 + 1
		|| (size % 2 == 0) && numbers->smallest_a < size/2) && to_do->sa == 0)
		to_do->ra = 1;
	//------CONFIG RRA--------//
	else if (numbers->smallest_a != 1 && ((size % 2 == 1) && numbers->smallest_a >= size/2 + 1
		|| (size % 2 == 0) && numbers->smallest_a >= size/2) && to_do->sa == 0)
		to_do->rra = 1;
	return (0);
}

void	exec_sa(t_swap *number)
{
	int	hold;

	hold = number->numbers_a[1];
	number->numbers_a[1] = number->numbers_a[0];
	number->numbers_a[0] = hold;
	ft_putstr("sa\n");
}

void	exec_ra(t_swap *number)
{
	int	hold[number->limit_a];
	int i;

	i = 1;
	hold[number->limit_a - 1] = number->numbers_a[0];
	while (i < number->limit_a)
	{
		hold[i - 1] = number->numbers_a[i];
		i++;
	}
	i = 0;
	while (i < number->limit_a)
	{
		number->numbers_a[i] = hold[i];
		i++;
	}
}

void	exec_rra(t_swap *number)
{
	int	hold[number->limit_a];
	int i;

	i = 1;
	hold[0] = number->numbers_a[number->limit_a - 1];
	while (i < number->limit_a)
	{
		hold[i] = number->numbers_a[i - 1];
		i++;
	}
	i = 0;
	while (i < number->limit_a)
	{
		number->numbers_a[i] = hold[i];
		i++;
	}
	ft_putstr("rra\n");
}

void	exec_pb(t_swap *number)
{
	exec_ra(number);
	number->limit_b += 1;
	number->numbers_b[number->limit_b] = number->numbers_a[number->limit_a];//usar o exec_rrb dps;
	number->numbers_a[number->limit_a] = 0;
	number->limit_a -= 1;
	ft_putstr("pb\n");
}

int	pb_case1(t_swap *number)
{
	int	i;

	i = 2;
	if (number->limit_a == 3)
		return (0);
	while (i < number->limit_a)
	{
		if (number->numbers_a[i - 1] > number->numbers_a[i])
			return (1);//não esta organizado 
		i++;
	}
	return (0);
}
