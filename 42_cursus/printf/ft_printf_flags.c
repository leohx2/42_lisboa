/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:13:56 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/08 22:50:28 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
o intuito dessa função final step é ler o conteudo dentro e imprimir as flags corretamente,
irá receber exatamente o q precisa imprimir ou alinhar. as flags por enquanto são apenas
".-0*"  
*/
int	ft_final_step(char *set, va_list *list, char **buffer)
{
	int	len;

	len = 0;
	while (*set)
	{
		//printf("\nSET ->%s\n",set);
		if (*set == 'Z' && !ft_strchr(set, '-') && 
			ft_is_last(set, 3) == 1)
			len += ft_set_flag(&set, list, buffer, 'Z');
		else if (*set == '-' && (ft_is_last(set, 3) == 1) && ft_rvlen(set) < 2)
			len += ft_set_flag(&set, list, buffer, '-');
		else if (*set == '.')
			len += ft_set_flag(&set, list, buffer, '.');
		else if (ft_is_last(set, 3) == 1)
			len += ft_set_flag(&set, list, buffer, 'd');
		else if (ft_is_last(set, 3) == 3 && !ft_is_in_set(*set, "z*.-"))
			len += ft_set_flag(&set, list, buffer, 'D');
		else
			set++;
	}
	free_bird(set);
	if (**buffer == '%')
		return (len + ft_replacing(buffer, *list));
	return (len);
}

static void	ft_move(char *set, int *index2, int list_arg)
{
	char *test1;

	if (list_arg == 0)
		return ;
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
static int	ft_set(char **buffer, char *set, va_list *list, int *index2)
{
	if (**buffer == '-' && !ft_strchr(set, '-') 
			&& *index2 <= 1)
		set[*index2] = **buffer;
	else if (**buffer == '0' && (ft_isdigit(set[*index2 - 1]) || 
			set[*index2 - 1] == '.') && ft_is_last(*buffer, 1) == 1)
			set[*index2] = '0';
	else if (**buffer == '0' && !ft_isdigit(*(*buffer - 1))
			&& !ft_strchr(set, '-') && !ft_strchr(set, 'Z') &&
			ft_is_last(*buffer, 4) == 1 && *(*buffer - 1) != '.')
		set[*index2] = 'Z';
	else if (**buffer == '.' && !ft_strchr(set, '.')
			&& ((ft_isdigit(*(*buffer + 1)) || *(*buffer + 1) == '*')
			|| ft_isdigit(set[*index2 - 1]) || ft_is_last(*buffer, 2)))
		set[*index2] = '.';
	else if (**buffer == '*' && ft_is_last(*buffer, 2) &&
		!ft_isdigit(*(*buffer + 1)))
		ft_move(set, index2, va_arg(*list, int));
	else if (ft_isdigit(**buffer) && **buffer != '0' 
			&& ft_is_last(*buffer, 2))
		set[*index2] = **buffer;
	else
		return (0);
	return (1);
}

int			ft_printf_flags(char **buffer, va_list *list)
{
	char	*set;
	int		index2;

	set = (char*)ft_calloc(sizeof(char), 1024);
	index2 = 0;
	*buffer += 1;
	while (ft_is_in_set(**buffer, "-.*0123456789"))
	{
		if	(ft_set(buffer, set, list, &index2) == 1)
			index2++;
		*buffer += 1;
	}
	//printf("set -> %s\n", set);
	return(ft_final_step(set, list, buffer));
}