/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:13:56 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/10 15:19:29 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
o intuito dessa função final step é ler o conteudo dentro e imprimir as flags corretamente,
irá receber exatamente o q precisa imprimir ou alinhar. as flags por enquanto são apenas
".-0*"  
*/
int	ft_final_step(set_str *set, va_list *list)
{
	int	len;

	len = 0;
	while (*set->set)
	{
		//printf("\nSET ->%s\n",set);
		if (*set->set == 'Z' && !ft_strchr(set->set, '-') && 
			ft_is_last(set->set, 3) == 1)
			len += ft_set_flag(set, list, 'Z');
		else if (*set->set == '-' && (ft_is_last(set->set, 3) == 1) && ft_rvlen(set->set) < 2)
			len += ft_set_flag(set, list, '-');
		else if (*set->set == '.')
			len += ft_set_flag(set, list, '.');
		else if (ft_is_last(set->set, 3) == 1)
			len += ft_set_flag(set, list, 'd');
		else if (ft_is_last(set->set, 3) == 3 && !ft_is_in_set(*set->set, "z*.-"))
			len += ft_set_flag(set, list, 'D');
		else
			set->set += 1;
	}
	free_bird(set->set);
	if (*set->buffer == '%')
		return (len + ft_replacing(set, list));
	return (len);
}

static void	ft_move(char *set, int *index2, int list_arg)
{
	char *test1;

	test1 = ft_itoa(list_arg);
	ft_memmove(set + *index2, test1, ft_strlen(test1));
	*index2 += ft_strlen(test1) - 1;
	if (test1)
		free(test1);
}

/*
a funcção ft_set é responsável por formar um set com somente aquilo q posso usar, imaginando ter 
uma sequencia de flags  iguais, "------", ou flags que são ignoradas em caso da presença de outra, como
"000----0000", essa função é responsável por transformar os respectivos exemplos em "-" e "0-" e
na proxima função, será feito o restante. ps o nome esta estranho, mas a primeira ideia tinha sido
ft_set_set, informação inutil do dia.
*/
static int	ft_set(set_str *set, va_list *list, int *index2)
{
	if (*set->buffer == '-' && !ft_strchr(set->set, '-') 
			&& *index2 <= 1)
		set->set[*index2] = *set->buffer;
	else if (*set->buffer == '0' && (ft_isdigit(set->set[*index2 - 1]) || 
			set->set[*index2 - 1] == '.') && ft_is_last(set->buffer, 1) == 1
			&& set->set[*index2 - 1] != '0')
			set->set[*index2] = '0';
	else if (*set->buffer == '0' && !ft_isdigit(*(set->buffer - 1))
			&& !ft_strchr(set->set, '-') && !ft_strchr(set->set, 'Z') &&
			ft_is_last(set->buffer, 4) == 1 && *(set->buffer - 1) != '.')
		set->set[*index2] = 'Z';
	else if (*set->buffer == '.' && !ft_strchr(set->set, '.')
			&& ((ft_isdigit(*(set->buffer + 1)) || *(set->buffer + 1) == '*')
			|| ft_isdigit(set->set[*index2 - 1]) || ft_is_last(set->buffer, 2)))
		set->set[*index2] = '.';
	else if (*set->buffer == '*' && ft_is_last(set->buffer, 2) &&
		!ft_isdigit(*(set->buffer + 1)))
		ft_move(set->set, index2, va_arg(*list, int));
	else if (ft_isdigit(*set->buffer) && *set->buffer != '0' 
			&& ft_is_last(set->buffer, 2))
		set->set[*index2] = *set->buffer;
	else
		return (0);
	return (1);
}

int			ft_printf_flags(set_str *set, va_list *list)
{
	int		index2;

	set->set = (char*)ft_calloc(sizeof(char), 1024);
	index2 = 0;
	set->buffer += 1;
	while (ft_is_in_set(*set->buffer, "-.*0123456789"))
	{
		if	(ft_set(set, list, &index2) == 1)
			index2++;
		set->buffer += 1;
	}
	//printf("set -> %s\n", set.set);
	return(ft_final_step(set, list));
}