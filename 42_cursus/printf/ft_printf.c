/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:33:07 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/05 18:59:28 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_replacing(char *buffer, va_list list, int *i_main)
{
	char *aux;
	int len;

	len = 0;
	while (buffer[*i_main])
	{
		if (buffer[*i_main] == '%')
		{
			if (buffer[*i_main + 1] != '%')
				len += ft_printf_flags(i_main, buffer, &list);
			aux = ft_return_type(buffer, i_main, &list);
			if (buffer[*i_main] == 'c' && aux && !aux[0])
				len += ft_putchar(-1);
			if (aux)
			{
				len += ft_putstr(aux);
				free(aux);
			}
		}
		else
			len += ft_putchar(buffer[*i_main]);
		if (buffer[*i_main] != '%' && buffer[*i_main] != '\0')
			*i_main += 1;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int 	index;
	int		len;

	index = 0;
	va_start(list, format);
	len = ft_replacing((char*)format, list, &index);
	va_end(list);
	return (len);
}
