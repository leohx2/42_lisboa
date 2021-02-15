/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:10:41 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/15 18:57:29 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_value(int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		count *= 10;
		n /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*to_return;
	int		aux;
	int		nmbr_size;

	aux = 0;
	if (!(to_return = (char*)malloc(11 * sizeof(char))))
		return (0);
	if (n == -2147483648)
		return (to_return = "-2147483648\0");
	if (n < 0)
	{
		to_return[aux++] = '-';
		n *= -1;
	}
	nmbr_size = ft_value(n);
	while (nmbr_size > 1 && n > 9)
	{
		to_return[aux++] = (n / nmbr_size) + 48;
		n = n % nmbr_size;
		nmbr_size /= 10;
	}
	to_return[aux++] = (n % 10) + 48;
	to_return[aux++] = '\0';
	return (to_return);
}
