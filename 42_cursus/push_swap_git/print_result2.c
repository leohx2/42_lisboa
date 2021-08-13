/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:03:57 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 14:18:58 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ra(t_swap *numbers)
{
	exec_rr(numbers, 'a', numbers->limit_a);
	ft_putstr("ra\n");
}

void	print_rb(t_swap *numbers)
{
	exec_rr(numbers, 'b', numbers->limit_b);
	ft_putstr("rb\n");
}

void	print_rr(t_swap *numbers)
{
	exec_rr(numbers, 'a', numbers->limit_a);
	exec_rr(numbers, 'b', numbers->limit_b);
	ft_putstr("rr\n");
}

void	print_rra(t_swap *numbers)
{
	exec_rrr(numbers, 'a', numbers->limit_a);
	ft_putstr("rra\n");
}

void	print_rrb(t_swap *numbers)
{
	exec_rrr(numbers, 'b', numbers->limit_b);
	ft_putstr("rrb\n");
}
