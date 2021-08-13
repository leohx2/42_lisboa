/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_size.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:37:14 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 11:48:36 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	snd_small_a(t_swap *numbers)
{
	int	i;
	int	s_smallest;

	i = 0;
	s_smallest = 0;
	if (numbers->smallest_a == 0)
		s_smallest = 1;
	while (i < numbers->limit_a)
	{
		if (numbers->numbers_a[i] < numbers->numbers_a[s_smallest]
			&& (i != numbers->smallest_a))
			s_smallest = i;
		i++;
	}
	return (s_smallest);
}

int	snd_big_a(t_swap *numbers)
{
	int	i;
	int	s_biggest;

	i = 0;
	s_biggest = 0;
	if (numbers->biggest_a == 0)
		s_biggest = 1;
	while (i < numbers->limit_a)
	{
		if (numbers->numbers_a[i] > numbers->numbers_a[s_biggest]
			&& (i != numbers->biggest_a))
			s_biggest = i;
		i++;
	}
	return (s_biggest);
}

void	exec_ra(t_swap *number, int *hold, int limite)
{
	int	i;

	i = 1;
	hold[limite - 1] = number->numbers_a[0];
	while (i < limite)
	{
		hold[i - 1] = number->numbers_a[i];
		i++;
	}
	i = 0;
	while (i < limite)
	{
		number->numbers_a[i] = hold[i];
		i++;
	}
}

void	exec_rra(t_swap *number, int *hold, int limite)
{
	int	i;

	i = 1;
	hold[0] = number->numbers_a[limite - 1];
	while (i < limite)
	{
		hold[i] = number->numbers_a[i - 1];
		i++;
	}
	i = 0;
	while (i < limite)
	{
		number->numbers_a[i] = hold[i];
		i++;
	}
}
