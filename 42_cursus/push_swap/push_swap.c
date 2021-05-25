/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:05:19 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/25 13:15:11 by lrosendo         ###   ########.fr       */
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
	normalize(&to_do);
	if (check_order(numbers))//dps colocar a ordem do stack B tbm!
	{
		order_a(numbers, numbers->argc - 1, &to_do);
	}
	ft_print_todo(to_do);
	//while (check_order(numbers) || safe < 10) // ainda verifica apenas a ordem do stack A 
	//{
	//	order_a(numbers);
	//	order_b(numbers); TO DO...
	//	safe++;
	//}
}

void	ft_print_todo(t_order to_do)
{
	if (to_do.sa == 1)
		ft_putstr("sa\n");
	if (to_do.sb == 1)
		ft_putstr("sb\n");
	if (to_do.ss == 1)
		ft_putstr("ss\n");
	if (to_do.pa == 1)
		ft_putstr("pa\n");
	if (to_do.pb == 1)
		ft_putstr("pb\n");
	if (to_do.ra == 1)
		ft_putstr("ra\n");
	if (to_do.rb == 1)
		ft_putstr("rb\n");
	if (to_do.rr == 1)
		ft_putstr("rr\n");
	if (to_do.rra == 1)
		ft_putstr("rra\n");
	if (to_do.rrb == 1)
		ft_putstr("rrb\n");
	if (to_do.rrr == 1)
		ft_putstr("rrr\n");
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
	free(numbers.numbers_a);
	free(numbers.numbers_b);
	printf("passou\n");
}

	//while (i < numbers.argc - 1)
	//{
	//	printf("%d\n",numbers.numbers_a[i]);
	//	i++;
	//}