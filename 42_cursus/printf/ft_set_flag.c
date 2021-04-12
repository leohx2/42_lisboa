/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:42:25 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 09:53:02 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_set_zd(int index2, set_str *set, int f)
{
	int		v_ret;
	int		helper;

	helper = 0;
	v_ret = 0;
	if (*set->str == '-' && f == 'Z' && ++helper)
		v_ret += ft_putchar('-');
	while (index2-- > 0)
	{
		if (f == 'Z')
			v_ret += ft_putchar(48);
		else
			v_ret += ft_putchar(32);
	}
	if (*set->buffer == 'c' && set->str && !set->str[0])
		v_ret += ft_putchar(-1);
	if (ft_dontprint(set) && !ft_is_null(set))
		v_ret += ft_putstr(set->str + helper);
	return (v_ret);
}

int	ft_set_minus(int index2, set_str *set, int D)//achar alguma fucking maneira de saber o argumento q vou receber, para poder imprimir corretamente
{
	int		v_ret;

	v_ret = 0;
	if (D > 0)
	{
		D = D - ft_strlen(set->str);
		while (D-- > 0)
			v_ret += ft_putchar(48);
	}
	v_ret +=  ft_putstr(set->str);
	if (*set->buffer == 'c' && set->str && !set->str[0])
		v_ret += ft_putchar(-1);
	while (index2-- > 0)
		v_ret += ft_putchar(32);
	return (v_ret);
}

static int ft_set_dot(int nmbr_int, set_str *set, int index2)
{
	int		aux;
	int		v_ret;
	int		helper;

	helper = 0;
	aux = ft_help_dot(set, &helper, &nmbr_int);
	v_ret = aux;
	if (*set->buffer == 'c' && set->str && !set->str[0])
			v_ret += ft_putchar(-1);
	if ((*set->buffer == 's' || *set->buffer == 'c') && nmbr_int >= 0)
		while(aux < nmbr_int && set->str && set->str[aux])
			v_ret += ft_putchar(set->str[aux++]);
	else if (nmbr_int < 0)
		v_ret += ft_putstr(set->str);
	else
	{
		while (aux++ < (nmbr_int - (int)ft_strlen(set->str)))
			v_ret += ft_putchar(48);
		if (ft_dontprint(set) && !ft_is_null(set))
			v_ret += ft_putstr(set->str + helper);
	}
	while (index2-- > 0)
		v_ret += ft_putchar(32);
	return (v_ret);
}

int ft_set_digit(int index2, char *nmbr_int1, set_str *set)
{
	char	nmbr_int2[20];
	int		neg;
	int		len;

	neg = 0;
	set->set += 1;
	if (*(set->set - ft_strlen(nmbr_int1) - 2) == '-')
		neg = 1;
	len = ft_rm_diff(index2, set);
	if (len > -1)
		return (len);
	len = 0;
	index2 = 0;
	while (ft_isdigit(*set->set) || *set->set == '-')
	{
		nmbr_int2[index2++] = *set->set;
		set->set += 1;
	}
	index2 = ft_index2(set, nmbr_int1, nmbr_int2);
	if (neg == 1)
		return (ft_set_dot(ft_atoi(nmbr_int2), set, index2));
	while (index2-- > 0)
		len += ft_putchar(32);
	return (ft_set_dot(ft_atoi(nmbr_int2), set, 0) + len);
}		

int ft_set_flag(set_str *set, va_list *list, int flag)
{
	dummy	aux;
	char	nmbr_a[20];

	aux.v_ret = 0;
	ft_index1(&set->set, flag, nmbr_a);
	if (ft_is_in_set(*set->set, "Z-*"))
		return(0);
	set->str = ft_return_type(&set->buffer, list);
	aux.index = ft_atoi(nmbr_a) - (int)ft_strlen(set->str);
	if (*set->buffer == 'c' && set->str && !set->str[0])
		aux.index--;
	if (flag == '-')
		aux.v_ret += (ft_set_minus(aux.index, set, 0));
	else if (flag == 'Z' || flag == 'd')
			aux.v_ret +=  (ft_set_zd(aux.index, set, flag));
	else if (flag == '.')
		aux.v_ret +=  (ft_set_dot(ft_atoi(nmbr_a), set, 0));
	else if (flag == 'D')
		aux.v_ret +=  (ft_set_digit(aux.index, nmbr_a, set));
	set->buffer += 1;
	if (*set->buffer != '%' && *set->buffer)
		aux.v_ret += ft_putchar(*set->buffer);
	free(set->str);
	return (aux.v_ret);
}

