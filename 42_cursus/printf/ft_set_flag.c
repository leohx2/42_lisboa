/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:42:25 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/23 01:19:36 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

//essa func tem como utilidade imprimir a flag 0; nmb = nmro para imprimir após as flags, tem de
// ser levado em consideração devido ao "len" do nmb
static int	ft_set_zd(int index2, char *str, char *buffer, int *i_main, int f)//arrumar para quando o nmro for negativo ou for str.
{
	int		value_return;
	value_return = 0;
	if (index2 > 0)
		value_return = index2;
	while (index2 > 0)
	{
		if (f == 'Z')
			ft_putchar(48);
		else
			ft_putchar(32);
		index2--;
	}
	ft_putstr(str);
	*i_main += 1;
	if (buffer[*i_main] != '%')
		ft_putchar(buffer[*i_main]);
	else
		*i_main += 1;
	free(str);
	return(value_return);
}

static int	ft_set_minus(int index2, char *str, char *buffer, int *i_main)//achar alguma fucking maneira de saber o argumento q vou receber, para poder imprimir corretamente
{
	int		value_return;

	value_return = 0;
	if (index2 > 0)
		value_return = index2;
	ft_putstr(str);
	while (index2 > 0)
	{
		ft_putchar(32);
		index2--;
	}
	*i_main += 1;
	if (buffer[*i_main] != '%')
		ft_putchar(buffer[*i_main]);
	else
		*i_main += 1;
	free(str);
	return(value_return);
}

static int ft_set_dot(int nmbr_int, char *str, char *buffer, int *i_main)
{
	int		value_return;

	value_return = 0;
	if (buffer[*i_main] == 's' || buffer[*i_main] == 'c')
		while(value_return < nmbr_int && str[value_return])
			ft_putchar(str[value_return++]);
	else
	{
		if (buffer[*i_main] == 'p')
			ft_putstr("0x");
		while (value_return < (nmbr_int - (int)ft_strlen(str)))
		{
			ft_putchar(48);
			value_return++;
		}
		ft_putstr(str);
		value_return += ft_strlen(str);
	}
	*i_main += 1;
	if (buffer[*i_main] != '%')
		ft_putchar(buffer[*i_main]);
	else
		*i_main += 1;
	free(str);
	return (value_return);
}

int ft_set_digit(char *set, int *index, va_list *list, char *buffer, int *i_main)
{
	char	size[20];
	int		index2;

	index2 = 0;
	*index += 1;
	while (ft_isdigit(set[*index]))
		size[index2++] = set[(*index)++];
	if (!ft_isdigit(set[*index + 1]))
	{}
	return (0);
}	

int ft_set_flag(char *set, int *index, va_list *list, char *buffer, 
	int *i_main, int flag)
{
	int		index2;
	char	nmbr_ascii[20];
	char	*str;

	index2 = 0;
	*index += 1;
	while (ft_isdigit(set[*index]))
		nmbr_ascii[index2++] = set[(*index)++];
	if (ft_is_in_set(set[*index], "Z-*"))
		return(0);
	str = ft_return_type(buffer, i_main, list);
	index2 = ft_atoi(nmbr_ascii) - (int)ft_strlen(str);
	if (flag == '-')
		return (ft_set_minus(index2, str, buffer, i_main));
	else if (flag == 'Z' || flag == 'd')
		return (ft_set_zd(index2, str, buffer, i_main, flag));
	else if (flag == '.')
		return (ft_set_dot(ft_atoi(nmbr_ascii), str, buffer, i_main));
	else if (flag == 'D')
	{
		printf("-->%i\n", set[*index + 1]);
		if (!(set[*index + 1]))
			return (ft_set_zd(index2, str, buffer, i_main, flag));
	}
	return (0);
}