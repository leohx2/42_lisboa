/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:52:38 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 13:43:49 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *argv)
{
	int	i;
	int	helper;

	helper = 0;
	i = 0;
	if (!ft_isdigit(argv[i]) && !ft_isdigit(argv[i + 1]))
		return (1);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			helper++;
			if (argv[i] != '-' && argv[i] != '+' || helper == 2)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_size(char *argv)
{
	if (ft_strlen(argv) > 1 && (ft_atoi(argv) == 0 || ft_atoi(argv) == 1))
		return (1);
	if (argv[0] != '-' && ft_atoi(argv) == ft_atoi("-2147483648"))
		return (1);
	if (!ft_isdigit(argv[ft_strlen(argv) - 1]))
		return (1);
	return (0);
}

int	check_repeated(t_swap numbers, int posicion)
{
	int	index;

	index = posicion - 1;
	while (index > 0)
	{
		if (ft_atoi(numbers.argv[posicion]) == ft_atoi(numbers.argv[index]))
			return (1);
		index--;
	}
	return (0);
}

int	error(t_swap numbers, int i)
{
	int	bol_error;

	bol_error = 0;
	bol_error += check_arg(numbers.argv[i]);
	bol_error += check_size(numbers.argv[i]);
	bol_error += check_repeated(numbers, i);
	return (bol_error);
}

int	check_error(t_swap numbers)
{
	int	i;

	i = 1;
	if (numbers.argc < 2)
		exit(EXIT_SUCCESS);
	while (i < numbers.argc)
	{
		if (error(numbers, i))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
