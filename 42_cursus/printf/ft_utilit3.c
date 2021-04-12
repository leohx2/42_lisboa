/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilit3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:06:04 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 20:41:04 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_bird(char *buffer)
{
	while (*(buffer - 1))
		buffer--;
	free(buffer);
}

int	ft_rvlen(char *buffer)
{
	int	size;

	size = 0;
	while (*(--buffer))
		size++;
	return (size);
}

int	isit_negative(char *str)
{
	int	index;

	index = -2;
	while (ft_isdigit(str[index]))
		index--;
	if (str[index] == '-')
		return (1);
	else
		return (0);
}

int	ft_is_last2(char *set)
{
	int	index;

	index = 1;
	while (ft_isdigit(set[index]))
		index++;
	if (ft_is_in_set(set[index], "Z-."))
		return (0);
	return (1);
}
