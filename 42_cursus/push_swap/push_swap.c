/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:05:19 by lrosendo          #+#    #+#             */
/*   Updated: 2021/07/20 12:37:35 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_numbers(t_swap *numbers)
{
	int i;

	i = 1;
	numbers->numbers_a = (int*)ft_calloc(sizeof(int), numbers->argc);
	numbers->numbers_b = (int*)ft_calloc(sizeof(int), numbers->argc);
	while (i < numbers->argc)
	{
		numbers->numbers_a[i - 1] = ft_atoi(numbers->argv[i]);
		i++;
	}
	
}

void	normalize(t_order *to_do)
{
	to_do->sa = 0;
	to_do->sb = 0;
	to_do->ss = 0;
	to_do->pa = 0;
	to_do->pb = 0;
	to_do->ra = 0;
	to_do->rb = 0;
	to_do->rr = 0;
	to_do->rra = 0;
	to_do->rrb = 0;
	to_do->rrr = 0;
}

void	printa_dpsTira(t_swap *numbers)
{
	int i = 0;
	
	printf("-------INICIO------\n");
	printf("------A\n");
	while (i < numbers->limit_a)
	{
		printf("%d\n",numbers->numbers_a[i]);
		i++;	
	}
	printf("------B\n");
	i = 0;
	while (i < numbers->limit_b)
	{
		printf("%d\n",numbers->numbers_b[i]);
		i++;	
	}
	printf("-------FIM------\n");
}

void	loop_ordering(t_swap *numbers)
{
	t_order to_do;

	numbers->limit_a = numbers->argc - 1;
	numbers->limit_b = 0;
	numbers->b_used = 0;
	if (numbers->argc > 6) // somente se houver 6 ou mais itens passados.
		more_than_five(numbers, &to_do);
	else
		five_or_less(numbers, &to_do);
}

void	ft_print_todo(t_swap *numbers, t_order to_do)
{
	if (to_do.sa == 1)
	{
		exec_ss(numbers, 'a');
		ft_putstr("sa\n");
	}
	if (to_do.sb == 1)
	{
		exec_ss(numbers, 'b');
		ft_putstr("sb\n");
	}
	if (to_do.ss == 1)
	{
		exec_ss(numbers, 'a');
		exec_ss(numbers, 'b');
		ft_putstr("ss\n");
	}
	if (to_do.pa == 1)
	{
		exec_pp(numbers, 'b');
		ft_putstr("pa\n");
	}
	if (to_do.pb == 1)
	{
		exec_pp(numbers, 'a');
		ft_putstr("pb\n");
	}
	if (to_do.ra == 1)
	{
		exec_rr(numbers, 'a', numbers->limit_a);
		ft_putstr("ra\n");
	}
	if (to_do.rb == 1)
	{
		exec_rr(numbers, 'b', numbers->limit_b);
		ft_putstr("rb\n");
	}
	if (to_do.rr == 1)
	{
		exec_rr(numbers, 'a', numbers->limit_a);
		ft_putstr("ra\n");
	}
	if (to_do.rra == 1)
	{
		exec_rrr(numbers, 'a', numbers->limit_a);
		ft_putstr("rra\n");
	}
	if (to_do.rrb == 1)
	{
		exec_rrr(numbers, 'b', numbers->limit_b);
		ft_putstr("rrb\n");
	}
	if (to_do.rrr == 1)
	{
		exec_rrr(numbers, 'a', numbers->limit_b);
		exec_rrr(numbers, 'b', numbers->limit_b);
		ft_putstr("rrr\n");
	}
}

int		main(int argc, char **argv)
{
	t_swap	numbers;
	int		i;

	i = 0;
	numbers.argc = argc;
	numbers.argv = argv;
	check_error(numbers);
	get_numbers(&numbers);
	loop_ordering(&numbers);
	printa_dpsTira(&numbers);
	free(numbers.numbers_a);
	free(numbers.numbers_b);
	printf("PASSOU!\n");
}

	//while (i < numbers.limit_a)
	//{
	//	printf("*%d\n",numbers.numbers_a[i]);
	//	i++;
	//}

