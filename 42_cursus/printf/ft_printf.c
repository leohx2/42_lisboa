/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:33:07 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 19:55:17 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_replacing(t_set *set, va_list *list)
{
	char	*aux;
	int		len;

	len = 0;
	while (*set->buffer)
	{
		if (*set->buffer == '%')
		{
			if (*(set->buffer + 1) != '%')
				len += ft_printf_flags(set, list);
			aux = ft_return_type(&set->buffer, list);
			if (*set->buffer == 'c' && aux && !aux[0])
				len += ft_putchar(-1);
			if (aux)
			{
				len += ft_putstr(aux);
				free(aux);
			}
		}
		else
			len += ft_putchar(*set->buffer);
		if (*set->buffer != '%' && *set->buffer != '\0')
			set->buffer += 1;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		len;
	t_set	set;

	set.buffer = (char *)format;
	va_start(list, format);
	len = ft_replacing(&set, &list);
	va_end(list);
	return (len);
}
