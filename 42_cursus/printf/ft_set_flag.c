/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:42:25 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/05 18:57:20 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_set_zd(char *set, int index2, char *str, char *buffer, int *i_main,
		 int f)
{
	int		v_ret;
	int		helper;

	helper = 0;
	v_ret = 0;
	if (*str == '-' && f == 'Z' && ++helper)
		v_ret += ft_putchar('-');
	while (index2-- > 0)
	{
		if (f == 'Z')
			v_ret += ft_putchar(48);
		else
			v_ret += ft_putchar(32);
	}
	if (buffer[*i_main] == 'c' && str && !str[0])
		v_ret += ft_putchar(-1);
	if (ft_dontprint(set, str, buffer, *i_main))
		v_ret += ft_putstr(str + helper);
	*i_main += 1;
	if (buffer[*i_main] != '%' && buffer[*i_main])//
		v_ret += ft_putchar(buffer[*i_main]);
	if (str)
		free(str);
	return (v_ret);
}

int	ft_set_minus(int index2, char *str, char *buffer, int *i_main, int D)
{
	int		v_ret;

	v_ret = 0;
	if (D > 0)
	{
		D = D - ft_strlen(str);
		while (D-- > 0)
			v_ret += ft_putchar(48);
	}
	v_ret +=  ft_putstr(str);
	if (buffer[*i_main] == 'c' && str && !str[0])
		v_ret += ft_putchar(-1);
	while (index2-- > 0)
		v_ret += ft_putchar(32);
	*i_main += 1;
	if (buffer[*i_main] != '%' && buffer[*i_main])
		v_ret += ft_putchar(buffer[*i_main]);
	if (str)
		free(str);
	return(v_ret);
}

static int ft_set_dot(int nmbr_int, char *str, char *buffer, int *i_main, 
		char *set, int index2, int helper)
{
	int		aux;
	int		v_ret;

	aux = ft_help_dot(str, buffer, *i_main, &helper, &nmbr_int);
	v_ret = aux;
	if (buffer[*i_main] == 'c' && str && !str[0])
			v_ret += ft_putchar(-1);
	if ((buffer[*i_main] == 's' || buffer[*i_main] == 'c') && nmbr_int >= 0)
		while (aux < nmbr_int && str && str[aux])
			v_ret += ft_putchar(str[aux++]);
	else if (nmbr_int < 0)
		v_ret += ft_putstr(str + helper);
	else
	{
		while (aux++ < (nmbr_int - (int)ft_strlen(str)))
			v_ret += ft_putchar(48);
		if (!ft_is_null(set, str) && ft_dontprint(set, str, buffer, *i_main))
			v_ret += ft_putstr(str + helper);
	}
	*i_main += 1;
	while (index2-- > 0)
		v_ret += ft_putchar(32);
	if (buffer[*i_main] != '%' && buffer[*i_main])
		v_ret += ft_putchar(buffer[*i_main]);
	free(str);
	return (v_ret);
}

int ft_set_digit(int index2, char *nmbr_int1, char *str, char *buffer, int *index,
	int *i_main, char *set)
{
	char	nmbr_int2[20];
	int		neg;
	int		len;

	neg = 0;
	*index += 1;
	len = ft_rm_diff(index2, nmbr_int1, str, buffer, index, i_main, set, &neg);
	if (len > -1)
		return (len);
	len = 0;
	index2 = 0;
	while (ft_isdigit(set[*index]) || set[*index] == '-')
		nmbr_int2[index2++] = set[(*index)++];
	index2 = ft_index2(buffer, *i_main, str, nmbr_int1, nmbr_int2);
	if (neg == 1)
		return (ft_set_dot(ft_atoi(nmbr_int2), str, buffer, i_main, set, 
				index2, 0));
	while (index2-- > 0)
		len += ft_putchar(32);
	return (ft_set_dot(ft_atoi(nmbr_int2), str, buffer, i_main, set, 0, 0)
			 + len);
}		

int ft_set_flag(char *set, int *index, va_list *list, char *buffer, 
	int *i_main, int flag)
{
	int		index2;
	char	nmbr_a[20];
	char	*str;

	index2 = 0;
	ft_index1(set, index, flag, nmbr_a);
	if (ft_is_in_set(set[*index], "Z-*"))
		return(0);
	str = ft_return_type(buffer, i_main, list);
	index2 = ft_atoi(nmbr_a) - (int)ft_strlen(str);
	if (buffer[*i_main] == 'c' && str && !str[0])
		index2--;
	if (flag == '-')
		return (ft_set_minus(index2, str, buffer, i_main, 0));
	else if (flag == 'Z' || flag == 'd')
			return (ft_set_zd(set, index2, str, buffer, i_main, flag));
	else if (flag == '.')
		return (ft_set_dot(ft_atoi(nmbr_a), str, buffer, i_main, set, 0, 0));
	else if (flag == 'D')
		return (ft_set_digit(index2, nmbr_a, str, buffer, index, i_main, set));
	return (0);
}
