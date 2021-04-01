/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:21:19 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/01 23:12:55 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int			ft_is_in_set(char c, char *set) //verificar se está no set, retornar 1 caso esteja
{
	int	i;

	i = 0;
	if (!c || !set)
		return (0);
	while(set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
/*
ft_after_it verifica se esse item passado possui alguama flag a frente dele, caso haja, não
deve adicionar um número. Terminar!
*/
int 		ft_is_last(char *set, int choice)
{
	int index;

	index = 1;
	while(ft_isdigit(set[index]))
		index++;
	if (choice == 1)
	{
		if(ft_is_in_set(set[index], "Z-*"))
			return (0);
		if(set[index] == '0' && set[index - 1] == '0')
			return (0);
	}
	if (choice == 3)
	{
		if(set[index] == '.')
			return (3);// a opção 3 me dirá q a seguir ao nmro possui um "."
		if(ft_is_in_set(set[index], "Z-*"))
			return (0);
	}
	if (choice == 4)
		if(ft_is_in_set(set[index], "Z-."))
			return (0);
	if (choice == 2)
		if(ft_is_in_set(set[index], "Z-*"))
			return (0);
	return (1);
}

static char	*ft_percent(char *buffer, int *i_main)
{
	char	*percent;
	percent = ft_calloc(3, sizeof(char));
	percent[0] = '%';
	if (buffer[*i_main] == '%' && buffer[*i_main + 1] && buffer[*i_main + 1] == '%')
		*i_main += 2;
	if (buffer[*i_main] != '%')
		percent[1] = buffer[*i_main];
	return (percent);
}

char		*ft_return_type(char *buffer, int *i_main, va_list *list)
{
	char *to_char;
	if (buffer[*i_main] == 's')//STRING
		{return (ft_strdup(va_arg(*list, char*)));}
	else if (buffer[*i_main] == 'c')//CHAR
		{
			to_char = ft_calloc(sizeof(char), 2);
			to_char[0] = va_arg(*list, int);
			return (to_char);
		}
	else if (buffer[*i_main] == '%')//%%
			return (ft_percent(buffer, i_main));
	else if (buffer[*i_main] == 'i' || buffer[*i_main] == 'd')// INTEIROS
		return (ft_itoa(va_arg(*list, int)));
	else if (buffer[*i_main] == 'u')//UNSIGNED
		return (ft_unsigned_itoa(va_arg(*list, unsigned int)));
	else if (buffer[*i_main] == 'x' || buffer[*i_main] == 'X')// HEXADECIMAL
		return (ft_print_hex(buffer[*i_main], va_arg(*list, long)));
	else if (buffer[*i_main] == 'p')// POINTER
		return (ft_print_memory(va_arg(*list, ULLONG)));
	return (NULL);
}
