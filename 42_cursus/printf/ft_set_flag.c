/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:42:25 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/10 14:26:12 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

//essa func tem como utilidade imprimir a flag 0; nmb = nmro para imprimir após as flags, tem de
// ser levado em consideração devido ao "len" do nmb
int	ft_set_zd(int index2, set_str *set, char **buffer, int f)//arrumar para quando o nmro for negativo ou for str..
{
	int		v_ret;
	int		helper;

	helper = 0;
	v_ret = 0;//value_return
	if (*set->str == '-' && f == 'Z' && ++helper)
		v_ret += ft_putchar('-');
	while (index2-- > 0)
	{
		if (f == 'Z')
			v_ret += ft_putchar(48);
		else
			v_ret += ft_putchar(32);
	}
	if (**buffer == 'c' && set->str && !set->str[0])
		v_ret += ft_putchar(-1);
	if (ft_dontprint(set, buffer) && !ft_is_null(set))
		v_ret += ft_putstr(set->str + helper);
	return (v_ret);
}

int	ft_set_minus(int index2, set_str *set, char **buffer, int D)//achar alguma fucking maneira de saber o argumento q vou receber, para poder imprimir corretamente
{
	int		v_ret;

	//printf("\nbuffer1 -> %s\n", *buffer);
	v_ret = 0;//value_return
	if (D > 0)
	{
		D = D - ft_strlen(set->str);
		while (D-- > 0)
			v_ret += ft_putchar(48);
	}
	v_ret +=  ft_putstr(set->str);
	if (**buffer == 'c' && set->str && !set->str[0])
		v_ret += ft_putchar(-1);
	while (index2-- > 0)
		v_ret += ft_putchar(32);
	return (v_ret);
}

static int ft_set_dot(int nmbr_int, set_str *set, char **buffer, int index2)
{
	int		aux;
	int		v_ret;
	int		helper;
	//printf("\nNMBR -> %i\n", nmbr_int);
	helper = 0;
	aux = ft_help_dot(set->str, buffer, &helper, &nmbr_int);
	v_ret = aux;
	if (**buffer == 'c' && set->str && !set->str[0])
			v_ret += ft_putchar(-1);// verificando quando temos q imprimir um 0/;
	if ((**buffer == 's' || **buffer == 'c') && nmbr_int >= 0)
		while(aux < nmbr_int && set->str && set->str[aux])
			v_ret += ft_putchar(set->str[aux++]);
	else if (nmbr_int < 0)
		v_ret += ft_putstr(set->str);
	else
	{
		while (aux++ < (nmbr_int - (int)ft_strlen(set->str)))
			v_ret += ft_putchar(48);
		if (ft_dontprint(set, buffer) && !ft_is_null(set))// e seu usar o buffer?
			v_ret += ft_putstr(set->str + helper);
	}
	while (index2-- > 0)
		v_ret += ft_putchar(32);
	return (v_ret);
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
int ft_set_digit(int index2, char *nmbr_int1,char **buffer, set_str *set)
{
	char	nmbr_int2[20];
	int		neg;
	int		len;

	neg = 0;
	set->set += 1;
	if (*(set->set - ft_strlen(nmbr_int1) - 2) == '-')
		neg = 1;
	len = ft_rm_diff(index2, set, buffer);
	if (len > -1)
		return (len);
	len = 0;// voltando a 0, -1 siginifica que o rm_diff não redirecionou pra outro lado.
	index2 = 0;
	while (ft_isdigit(*set->set) || *set->set == '-')
	{
		nmbr_int2[index2++] = *set->set;
		set->set += 1;
	}
	index2 = ft_index2(buffer, set->str, nmbr_int1, nmbr_int2);
	//printf("INDEX2 -> %i\n", index2);
	if (neg == 1)
		return (ft_set_dot(ft_atoi(nmbr_int2), set, buffer, index2));
	while (index2-- > 0)
		len += ft_putchar(32);
	return (ft_set_dot(ft_atoi(nmbr_int2), set, buffer, 0) + len);
}		

int ft_set_flag(set_str *set, va_list *list, char **buffer, int flag)
{
	int		index2;
	char	nmbr_a[20];
	int		v_ret;
	//printf("\nFLAG -> %c\n", flag);
	v_ret = 0;
	index2 = 0;
	ft_index1(&set->set, flag, nmbr_a);//aqui!
	if (ft_is_in_set(*set->set, "Z-*"))
		return(v_ret);
	set->str = ft_return_type(buffer, list);
	index2 = ft_atoi(nmbr_a) - (int)ft_strlen(set->str);
	if (**buffer == 'c' && set->str && !set->str[0])
		index2--;
	if (flag == '-')
		v_ret += (ft_set_minus(index2, set, buffer, 0));
	else if (flag == 'Z' || flag == 'd')
			v_ret +=  (ft_set_zd(index2, set, buffer, flag));
	else if (flag == '.')
		v_ret +=  (ft_set_dot(ft_atoi(nmbr_a), set, buffer, 0));
	else if (flag == 'D')
		v_ret +=  (ft_set_digit(index2, nmbr_a, buffer, set));
	*buffer += 1;
	if (**buffer != '%' && **buffer)
		v_ret += ft_putchar(**buffer);
	free(set->str);
	return (v_ret);
}

