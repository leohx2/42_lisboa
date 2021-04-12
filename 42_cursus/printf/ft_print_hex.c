/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:20:00 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 19:24:36 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_invert(char *hexa)
{
	int		index;
	int		index2;
	char	*temp;

	temp = (char *)ft_calloc(sizeof(char), ft_strlen(hexa) + 1);
	index = ft_strlen(hexa);
	index2 = 0;
	while (hexa[index2])
	{
		temp[index2] = hexa[index - index2 - 1];
		index2++;
	}
	free(hexa);
	return (temp);
}

char	*ft_print_hex(char letter, TEST nmb)
{
	long	temp;
	char	*hexa;
	int		index;

	if (nmb > 4294967295)
		nmb = 4294967295;
	else if (nmb == 0)
		return (ft_strdup("0"));
	hexa = (char *)ft_calloc(sizeof(char), 100);
	index = 0;
	while (nmb != 0)
	{
		temp = nmb % 16;
		if (temp < 10)
			temp = temp + 48;
		else if (temp >= 10 && letter == 'X')
			temp = temp + 55;
		else
			temp = temp + 87;
		hexa[index++] = temp;
		nmb = nmb / 16;
	}
	return (ft_invert(hexa));
}

char	*ft_print_memory(ULLONG nmb)
{
	ULLONG	temp;
	char	*hexa;
	int		index;

	if (nmb == 0)
		return (ft_strdup("0x0"));
	else if (nmb == 0)
		return (ft_strdup("0"));
	hexa = (char *)ft_calloc(sizeof(char), 100);
	index = 0;
	while (nmb != 0)
	{
		temp = nmb % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hexa[index++] = temp;
		nmb = nmb / 16;
	}
	hexa[index++] = 'x';
	hexa[index++] = '0';
	return (ft_invert(hexa));
}
