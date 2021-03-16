/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:33:07 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/16 13:29:37 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_replacing(char *buffer, va_list list)//
{
	int		index;

	index = 0;
	while (buffer[index])
	{
		if (buffer[index] == '%')
		{
			if (buffer[index + 1] == 's')//STRING
				ft_putstr(va_arg(list, char*));
			else if (buffer[index + 1] == 'c')//CHAR
				ft_putchar(va_arg(list, int));
			else if (buffer[index + 1] == '%')//%%
				ft_putchar('%');
			else if (buffer[index + 1] == 'i' || buffer[index + 1] == 'd')// INTEIROS
				ft_putstr(ft_itoa(va_arg(list, int)));
			else if (buffer[index + 1] == 'u')//UNSIGNED
				ft_putstr(ft_unsigned_itoa(va_arg(list, unsigned int)));
			else if (buffer[index + 1] == 'x' || buffer[index + 1] == 'X'
					|| buffer[index + 1] == 'p')// HEXADECIMAL OR POINTER
				ft_print_hex(buffer[index + 1], va_arg(list, ULLONG));
			index++;
		}
		else
			ft_putchar(buffer[index]);
		index++;
	}
}

int			ft_printf(const char *format, ...) //retornar o nmro de caracteres impresso em caso de sucesso e < 0 em caso de falhas.
{
	va_list	list;
	char	*buffer;

	va_start(list, format);
	if (!(ft_strchr(format, '%')))
	{
		ft_putstr(format);
		return (0);
	}
	buffer = ft_strdup(format);
	ft_replacing(buffer, list);
	va_end(list);
	free(buffer);
	return 0;//verificar se este return esta correto, colocado de forma provisoria para realizar os testes.
}