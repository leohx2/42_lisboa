/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:42:25 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/01 20:44:22 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

//essa func tem como utilidade imprimir a flag 0; nmb = nmro para imprimir após as flags, tem de
// ser levado em consideração devido ao "len" do nmb
int	ft_set_zd(char *set, int index2, char *str, char *buffer, int *i_main,
		 int f)//arrumar para quando o nmro for negativo ou for str..
{
	int		v_ret;
	int		helper;

	helper = 0;
	v_ret = 0;//value_return
	if (*str == '-' && f == 'Z' && ++helper)
		v_ret += ft_putchar('-');
	while (index2 > 0)
	{
		if (f == 'Z')
			v_ret += ft_putchar(48);
		else
			v_ret += ft_putchar(32);
		index2--;
	}
	if (buffer[*i_main] == 'c' && str && !str[0])
		v_ret += ft_putchar(-1);
	if (ft_dontprint(set, str, buffer, *i_main))
		v_ret += ft_putstr(str + helper);
	*i_main += 1;
	if (buffer[*i_main] != '%')
		v_ret += ft_putchar(buffer[*i_main]);
	if (str)
		free(str);
	return(v_ret);
}

int	ft_set_minus(int index2, char *str, char *buffer, int *i_main, int D)//achar alguma fucking maneira de saber o argumento q vou receber, para poder imprimir corretamente
{
	int		v_ret;

	v_ret = 0;//value_return
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
	if (buffer[*i_main] != '%')
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
			v_ret += ft_putchar(-1);// verificando quando temos q imprimir um 0/;
	if (buffer[*i_main] == 's' || buffer[*i_main] == 'c' )
		while(aux < nmbr_int && str && str[aux])
			v_ret += ft_putchar(str[aux++]);
	else
	{
		while (aux++ < (nmbr_int - (int)ft_strlen(str)))
			v_ret += ft_putchar(48);
		if (!ft_is_null(set, str))
			v_ret += ft_putstr(str + helper);
	}
	*i_main += 1;
	while (index2-- > 0)
		v_ret += ft_putchar(32);
	if (buffer[*i_main] != '%')
		v_ret += ft_putchar(buffer[*i_main]);
	free(str);
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
	len = 0;// voltando a 0, -1 siginifica que o rm_diff não redirecionou pra outro lado.
	index2 = 0;
	while (ft_isdigit(set[*index]))
		nmbr_int2[index2++] = set[(*index)++];
	if (buffer[*i_main] == 's' && (int)ft_strlen(str) < ft_atoi(nmbr_int2))//from here
		index2 = ft_atoi(nmbr_int1) - ft_strlen(str); 
	else if (ft_atoi(nmbr_int2) == 0)
		index2 = ft_atoi(nmbr_int1) - (int)ft_strlen(str);
	else if ((int)ft_strlen(str) > ft_atoi(nmbr_int2) && !ft_is_in_set(buffer[*i_main], "sc"))//verificar em caso de %c ou %d
		index2 = ft_atoi(nmbr_int1) - ft_strlen(str);
	else
		index2 = ft_atoi(nmbr_int1) - ft_atoi(nmbr_int2); 
	if (str[0] == '-' && ft_atoi(nmbr_int2) >= (int)ft_strlen(str))
		index2--;//to here
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
	//printf("FLAG -> %c\n", flag);
	index2 = 0;
	if (flag != 'D' && flag != 'd')//caso a Flag seja D, significa que é apenas DIGITO, sem flags a frente
		*index += 1;
	if (flag == 'D' || flag == 'd')
		while (!ft_isdigit(set[*index]))
			*index += 1;
	while (ft_isdigit(set[*index]))
		nmbr_a[index2++] = set[(*index)++];
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

