/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:52:38 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/17 11:59:26 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			if(argv[i] != '-' && argv[i] != '+')
			{
				ft_putstr("Error\n");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

void	check_size(char *argv)
{
	if (ft_strlen(argv) > 1 && ft_atoi(argv) == 1)
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	check_error(t_swap numbers)
{
	int i;

	i = 1;
	if (numbers.argc == 1)
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
	while (i < numbers.argc)
	{
		check_arg(numbers.argv[i]);
		check_size(numbers.argv[i]);
		i++;
	}
}
