/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_size.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:38:44 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 11:49:51 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	snd_small_b(t_swap *numbers)
{
	int	i;
	int	s_smallest;

	i = 0;
	s_smallest = 0;
	if (numbers->smallest_b == 0)
		s_smallest = 1;
	while (i < numbers->limit_b)
	{
		if (numbers->numbers_b[i] < numbers->numbers_b[s_smallest]
			&& (i != numbers->smallest_b))
			s_smallest = i;
		i++;
	}
	return (s_smallest);
}

int	snd_big_b(t_swap *numbers)
{
	int	i;
	int	s_biggest;

	i = 0;
	s_biggest = 0;
	if (numbers->biggest_b == 0)
		s_biggest = 1;
	while (i < numbers->limit_b)
	{
		if (numbers->numbers_b[i] > numbers->numbers_b[s_biggest]
			&& (i != numbers->biggest_b))
			s_biggest = i;
		i++;
	}
	return (s_biggest);
}

void	exec_rb(t_swap *number, int *hold, int limite)
{
	int	i;

	i = 1;
	hold[number->limit_b - 1] = number->numbers_b[0];
	while (i < limite)
	{
		hold[i - 1] = number->numbers_b[i];
		i++;
	}
	i = 0;
	while (i < limite)
	{
		number->numbers_b[i] = hold[i];
		i++;
	}
}

void	exec_rrb(t_swap *number, int *hold, int limite)
{
	int	i;

	i = 1;
	hold[0] = number->numbers_b[limite - 1];
	while (i < limite)
	{
		hold[i] = number->numbers_b[i - 1];
		i++;
	}
	i = 0;
	while (i < limite)
	{
		number->numbers_b[i] = hold[i];
		i++;
	}
}
