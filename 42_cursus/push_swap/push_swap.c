/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:05:19 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/26 11:18:41 by lrosendo         ###   ########.fr       */
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

void	loop_ordering(t_swap *numbers)
{
	int		safe;
	t_order to_do;

	safe = 0; //retirar isso dps, só para proteger de looping enquanto testo.
	numbers->limit_a = numbers->argc - 1;
	numbers->limit_b = 0;
	while (check_order(numbers) && safe < 10)//dps colocar a ordem do stack B tbm!
	{
		//printf("-------INICIO------\n");
		normalize(&to_do);
		order_a(numbers, numbers->argc - 1, &to_do);
		ft_print_todo(numbers, to_do);
		safe++;
		//exec_todo(numbers, &to_do); Refinar e deixar apenas os itens corretos, ex: se tiver Sa == 1 e Sb == 1, fazer SS = 1.
	}
	printf("SAFE VERIFY -> %d\t LIMIT -> %d\n", safe, numbers->limit_a);
	//while (check_order(numbers) || safe < 10) // ainda verifica apenas a ordem do stack A 
	//{
	//	order_a(numbers);
	//	order_b(numbers); TO DO...
	//	safe++;
	//}
}

void	ft_print_todo(t_swap *numbers, t_order to_do)
{
	if (to_do.sa == 1)
		exec_sa(numbers);
	if (to_do.sb == 1)
		ft_putstr("sb\n");//TO_DO
	if (to_do.ss == 1)
		ft_putstr("ss\n");//TO_DO
	if (to_do.pa == 1)
		ft_putstr("pa\n");//TO_DO
	if (to_do.pb == 1)
		exec_pb(numbers);
	if (to_do.ra == 1)
	{
		exec_ra(numbers);
		ft_putstr("ra\n");
	}
	if (to_do.rb == 1)
		ft_putstr("rb\n");//TO_DO
	if (to_do.rr == 1)
		ft_putstr("rr\n");//TO_DO
	if (to_do.rra == 1)
		exec_rra(numbers);
	if (to_do.rrb == 1)
		ft_putstr("rrb\n");//TO_DO
	if (to_do.rrr == 1)
		ft_putstr("rrr\n");//TO_DO
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
	while (i < numbers.limit_a)
	{
		printf("%d\n",numbers.numbers_a[i]);
		i++;
	}
	free(numbers.numbers_a);
	free(numbers.numbers_b);
	printf("passou\n");
}

	//while (i < numbers.argc - 1)
	//{
	//	printf("%d\n",numbers.numbers_a[i]);
	//	i++;
	//}