/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:33:17 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 14:24:30 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ss(t_swap *number, int stack)
{
	int	hold;

	if (stack == 'a')
	{
		hold = number->numbers_a[1];
		number->numbers_a[1] = number->numbers_a[0];
		number->numbers_a[0] = hold;
	}
	else if (stack == 'b')
	{
		hold = number->numbers_b[1];
		number->numbers_b[1] = number->numbers_b[0];
		number->numbers_b[0] = hold;
	}
}

void	exec_rr(t_swap *number, int stack, int limite)
{
	int	*hold;

	hold = (int *)malloc(sizeof(int) * limite);
	if (stack == 'a')
		exec_ra(number, hold, limite);
	else
		exec_rb(number, hold, limite);
	free (hold);
}

void	exec_rrr(t_swap *number, int stack, int limite)
{
	int	*hold;

	hold = (int *)malloc(sizeof(int) * limite);
	if (stack == 'a')
		exec_rra(number, hold, limite);
	else if (stack == 'b' && number->b_used)
		exec_rrb(number, hold, limite);
	free (hold);
}

void	exec_pp(t_swap *number, int stack)
{
	if (stack == 'a')
	{
		exec_rr(number, 'a', number->limit_a);
		number->numbers_b[number->limit_b]
			= number->numbers_a[number->limit_a - 1];
		number->limit_b += 1;
		number->b_used = 1;
		exec_rrr(number, 'b', number->limit_b);
		number->numbers_a[number->limit_a] = 0;
		number->limit_a -= 1;
		number->chunk_control += 1;
	}
	else
	{
		exec_rr(number, 'b', number->limit_b);
		number->numbers_a[number->limit_a]
			= number->numbers_b[number->limit_b - 1];
		number->limit_a += 1;
		exec_rrr(number, 'a', number->limit_a);
		number->numbers_b[number->limit_b] = 0;
		number->limit_b -= 1;
		if (number->limit_b <= 0)
			number->b_used = 0;
	}
}

int	pp_case1(t_swap *number, int stack)
{
	int	i;

	i = 1;
	if (stack == 'a')
	{
		if (number->limit_a == 3)
			return (0);
		while ((i++) < number->limit_a)
		{
			if (number->numbers_a[i - 1] > number->numbers_a[i])
				return (1);
		}
	}
	else
	{
		if (number->limit_b == 3)
			return (0);
		while ((i++) < number->limit_b)
		{
			if (number->numbers_b[i - 1] < number->numbers_b[i])
				return (1);
		}
	}
	return (0);
}
