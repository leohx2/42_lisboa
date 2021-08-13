/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:03:44 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 14:18:49 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sa(t_swap *numbers)
{
	exec_ss(numbers, 'a');
	ft_putstr("sa\n");
}

void	print_sb(t_swap *numbers)
{
	exec_ss(numbers, 'b');
	ft_putstr("sb\n");
}

void	print_ss(t_swap *numbers)
{
	exec_ss(numbers, 'a');
	exec_ss(numbers, 'b');
	ft_putstr("ss\n");
}

void	print_pa(t_swap *numbers)
{
	exec_pp(numbers, 'b');
	ft_putstr("pa\n");
}

void	print_pb(t_swap *numbers)
{
	exec_pp(numbers, 'a');
	ft_putstr("pb\n");
}
