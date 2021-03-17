/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:13:56 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/17 09:59:34 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
a ideia aqui é, colocar tudo dentro do set, todas as flags, seguidas pelos respectivos nmros ou 
quantidades. Dps em outra função verificar o char set, e imprimir de acordo com os nmros lá de
dentro :D, let see how it works
*/
static void	ft_move(char *set, int *index2, int list_arg)
{
	char	*temp;

	temp = ft_itoa(list_arg);
	while (*temp)
	{
		set[*index2] = *temp;
		*index2 += 1;
		temp++;
	}
	free(temp);
}

/*
a funcção ft_set é responsável por formar um set com somente aquilo q posso usar, imaginando ter 
uma sequencia de flags  iguais, "------", ou flags que são ignoradas em caso da presença de outra, como
"000----0000", essa função é responsável por transformar os respectivos exemplos em "-" e "0-" e
na proxima função, será feito o restante. ps o nome esta estranho, mas a primeira ideia tinha sido
ft_set_set, informação inutil do dia.
*/
static int	ft_set(char *buffer, char *set, int index, va_list *list,
					int index2)
{
	if (buffer[index] == '-' && !ft_strchr(set, '-') 
			&& index2 <= 1)
		set[index2++] = buffer[index];
	else if (buffer[index] == '0' && !ft_isdigit(buffer[index - 1])
			&& !ft_strchr(set, '-') && !ft_strchr(set, 'Z'))
		set[index2++] = 'Z';
	else if (buffer[index] == '0' && ft_isdigit(set[index2 - 1]))
			set[index2++] = '0';
	else if (buffer[index] == '.' && !ft_strchr(set, '.')
			&& (ft_isdigit(buffer[index + 1]) || buffer[index + 1] == '*'))
		set[index2++] = '.';
	else if (buffer[index] == '*' && buffer[index + 1] != '*'
			&& !ft_isdigit(buffer[index - 1]))
		ft_move(set, &index2, va_arg(*list, int));
	else if (ft_isdigit(buffer[index]) && buffer[index - 1] != '*'
			&& buffer[index] != '0')
		set[index2++] = buffer[index];
	else
		return (0);
	return (1);
}

int			ft_printf_flags(int *index, char *buffer, va_list *list)
{
	char	*set;
	int		index2;

	index2 = 0;
	*index += 1;
	set = ft_calloc(sizeof(char), 1024);
	while (buffer[*index] == '-' || ft_isdigit(buffer[*index])
			|| buffer[*index] == '.' || buffer[*index] == '*')
	{
		if	(ft_set(buffer, set, *index, list, index2) == 1)
			index2++;
		*index += 1;
	}
	free(set);
	return(1);
}//verificar pq n esta imprimindo o set corretamente quando há mais de 1 % signal.