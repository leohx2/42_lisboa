/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:05:19 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/17 12:08:21 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_numbers(t_swap *numbers)
{
	int i;

	i = 1;
	printf("aqui?");
	numbers->numbers = (int*)ft_calloc(sizeof(int), numbers->argc);
	while (i < numbers->argc)
	{
		numbers->numbers[i - 1] = ft_atoi(numbers->argv[i]);
		i++;
	}
	
}

int		main(int argc, char **argv)
{
	t_swap numbers;
	int		i;
	i = 0;

	numbers.argc = argc;
	numbers.argv = argv;
	check_error(numbers);
	get_numbers(&numbers);
	while (i < numbers.argc)
	{
		printf("%d\n",numbers.numbers[i - 1]);
		i++;
	}
	
	printf("passou\n");
}