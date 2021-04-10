/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:33:07 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/10 14:41:34 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_replacing(char **buffer, va_list list)//
{
	char *aux;
	int len;

	len = 0;
	while (**buffer)
	{
		if (**buffer == '%')
		{
			if (*(*buffer + 1) != '%')
				len += ft_printf_flags(buffer, &list);
			aux = ft_return_type(buffer, &list);
			if (**buffer == 'c' && aux && !aux[0])
				len += ft_putchar(-1);
			if (aux)
			{
				len += ft_putstr(aux);
				free(aux);
			}
		}
		else
			len += ft_putchar(**buffer);
		if(**buffer != '%' && **buffer != '\0')	
			*buffer += 1;
	}
	return (len);
}

int	ft_printf(const char *format, ...) //retornar o nmro de caracteres impresso em caso de sucesso e < 0 em caso de falhas.
{
	va_list	list;
	int		len;
	char	*str;

	str = (char *)format;
	va_start(list, format);
	len = ft_replacing(&str, list);
	va_end(list);
	return (len);//verificar se este return esta correto, colocado de forma provisoria para realizar os testes.
}
