/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:20:00 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/16 13:31:25 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
char	*ft_invert(char *hexa)
{
	int		index;
	int		index2;
	char	*temp;

	if (!hexa)
		return (NULL);
	temp = (char*)ft_calloc(sizeof(char), ft_strlen(hexa) + 1);
	index = ft_strlen(hexa);
	index2 = 0;
	while (hexa[index2])
	{
		temp[index2] = hexa[index - index2 - 1]; 
		index2++;
	}
	free(hexa);
	return(temp);
}

void	ft_print_hex(char letter, unsigned long long int nmb)
{
	unsigned long long int 	temp;
	char					*hexa;
	int						index;

	if (nmb == 0)
	{
		ft_putchar(48);
		return ;
	}
	hexa = (char*)malloc(sizeof(char) * 100);
	index = 0;
	while (nmb != 0)
	{
		temp = nmb%16;
		if (temp < 10)
			temp = temp + 48;
		else if (temp >= 10 && letter == 'X')
			temp = temp + 55;
		else
			temp = temp + 87;
		hexa[index++] = temp;
		nmb = nmb / 16;
	}
	if (letter == 'p')
		ft_putstr("0x");
	hexa[index] = 0;
	hexa = ft_invert(hexa);
	ft_putstr(hexa);
	free(hexa);
}