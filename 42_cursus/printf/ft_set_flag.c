/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:42:25 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/25 17:24:23 by lrosendo         ###   ########.fr       */
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

static int	ft_set_minus(int index2, char *str, char *buffer, int *i_main, int D)//achar alguma fucking maneira de saber o argumento q vou receber, para poder imprimir corretamente
{
	int		value_return;

	value_return = 0;
	if (index2 > 0)
		value_return = index2;
	if (D > 0)
	{
		D = D - ft_strlen(str);
		while (D-- > 0)
			ft_putchar(48);
	}
	ft_putstr(str);
	while (index2-- > 0)
		ft_putchar(32);
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

/*
index, variavel auxiliar a qual vem com o valor de ft_atoi(nmbr_ascii) - (int)ft_strlen(str), caso
seja necessario chamar o ft_set_zd. Não sendo necessario ela recebe o valor de 0 e tem o proposito
de ser um index auxiliar. 
nmbr_int1 = se for o caso de ser uma flag valor1.valor2 o valor1 é atribuído ao nmbr_int1 para subtrair
com o nmbr_int2, q sera o valor2, assim poderei calcular quantos espaços imprimir corretamente.
str = versão em caracteres do proximo elemento da list,
buffer = format original do printf
*index = ultima casa do set analisada na ultima função,
*i_main = index da casa do buffer que estamos analisando.
*/
int ft_set_digit(int index2, char *nmbr_int1, char *str, char *buffer, int *index,
	int *i_main, char *set)
{
	char	nmbr_int2[20];

	*index += 1;
	if (!set[*index] && !ft_is_in_set(buffer[*i_main], "sc"))
		return (ft_set_zd(index2, str, buffer, i_main, 'D'));
	index2 = 0;
	while (ft_isdigit(set[*index]))
		nmbr_int2[index2++] = set[(*index)++];
	index2 = ft_atoi(nmbr_int1) - ft_atoi(nmbr_int2);
	while (index2 > 0)
	{
		ft_putchar(32); // usar uma flag no dot, para fazer isso em caso de menos
		index2--;
	}
	return (ft_set_dot(ft_atoi(nmbr_int2), str, buffer, i_main));
}		

int ft_set_flag(char *set, int *index, va_list *list, char *buffer, 
	int *i_main, int flag)
{
	int		index2;
	char	nmbr_a[20];
	char	*str;

	index2 = 0;
	if (flag != 'D' && flag != 'd')//caso a Flag seja D, significa que é apenas DIGITO, sem flags a frente
		*index += 1;
	while (ft_isdigit(set[*index]))
		nmbr_a[index2++] = set[(*index)++];
	if (ft_is_in_set(set[*index], "Z-*"))
		return(0);
	str = ft_return_type(buffer, i_main, list);
	index2 = ft_atoi(nmbr_a) - (int)ft_strlen(str);
	if (flag == '-')
		return (ft_set_minus(index2, str, buffer, i_main, 0));
	else if (flag == 'Z' || flag == 'd')
		return (ft_set_zd(index2, str, buffer, i_main, flag));
	else if (flag == '.')
		return (ft_set_dot(ft_atoi(nmbr_a), str, buffer, i_main));
	else if (flag == 'D')
		return (ft_set_digit(index2, nmbr_a, str, buffer, index, i_main, set));
	return (0);
}