/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:49:58 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/19 20:27:28 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int				signal;
	long long int	result;

	signal = 1;
	result = 0;

	while (*str == ' ' || *str == '\t' || *str == '\n'
	|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		signal = -1;
	}
	
	while (*str > 47 && *str < 58)
	{
		result = result * 10 + *str - 48;
		str++;
		if (result * signal < -2147483648)
			return (1);
		if (result * signal > 2147483647 && signal == 1)
			return (1);
	}
	return (result * signal);
}
