/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:33:07 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/17 00:10:18 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_replacing(char *buffer, va_list list, int *index)//
{
	while (buffer[*index])
	{
		if (buffer[*index] == '%')
		{
			ft_printf_flags(index, buffer, &list);
			if (buffer[*index] == 's')//STRING
				ft_putstr(va_arg(list, char*));
			else if (buffer[*index] == 'c')//CHAR
				ft_putchar(va_arg(list, int));
			else if (buffer[*index] == '%')//%%
				ft_putchar('%');
			else if (buffer[*index] == 'i' || buffer[*index] == 'd')// INTEIROS
				ft_putstr(ft_itoa(va_arg(list, int)));
			else if (buffer[*index] == 'u')//UNSIGNED
				ft_putstr(ft_unsigned_itoa(va_arg(list, unsigned int)));
			else if (buffer[*index] == 'x' || buffer[*index] == 'X'
					|| buffer[*index] == 'p')// HEXADECIMAL OR POINTER
				ft_print_hex(buffer[*index], va_arg(list, ULLONG));
		}
		else
			ft_putchar(buffer[*index]);
		*index += 1;
	}
}

int			ft_printf(const char *format, ...) //retornar o nmro de caracteres impresso em caso de sucesso e < 0 em caso de falhas.
{
	va_list	list;
	char	*buffer;
	int 	index;

	index = 0; // criei essa variavel só para desafogar umas linhas ali de cima 
	va_start(list, format);
	if (!(ft_strchr(format, '%')))
	{
		ft_putstr(format);
		return (0);
	}
	buffer = ft_strdup(format);
	ft_replacing(buffer, list, &index);
	va_end(list);
	free(buffer);
	return 0;//verificar se este return esta correto, colocado de forma provisoria para realizar os testes.
}