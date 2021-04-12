/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:21:19 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 09:35:51 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_in_set(char c, char *set)
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

int	ft_is_last(char *set, int choice)
{
	int	index;

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
			return (3);
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

static char	*ft_percent(char **buffer)
{
	char	*percent;

	percent = ft_calloc(3, sizeof(char));
	percent[0] = '%';
	if (**buffer == '%' && *(*buffer + 1) && *(*buffer + 1) == '%')
		*buffer += 2;
	if (**buffer != '%')
		percent[1] = **buffer;
	return (percent);
}

char	*ft_return_type(char **buffer, va_list *list)
{
	char *to_char;

	if (**buffer == 's')
		return (ft_strdup(va_arg(*list, char *)));
	else if (**buffer == 'c')
	{
		to_char = ft_calloc(sizeof(char), 2);
		to_char[0] = va_arg(*list, int);
		return (to_char);
	}
	else if (**buffer == '%')
		return (ft_percent(buffer));
	else if (**buffer == 'i' || **buffer == 'd')
		return (ft_itoa(va_arg(*list, int)));
	else if (**buffer == 'u')
		return (ft_unsigned_itoa(va_arg(*list, unsigned int)));
	else if (**buffer == 'x' || **buffer == 'X')
		return (ft_print_hex(**buffer, va_arg(*list, TEST)));
	else if (**buffer == 'p')
		return (ft_print_memory(va_arg(*list, ULLONG)));
	return (NULL);
}

void	ft_index1(char **set, int flag, char *nmbr_a)
{
	int		index2;

	index2 = 0;
	if (flag != 'D' && flag != 'd')
		*set += 1;
	else if (flag == 'D' || flag == 'd')
		while (!ft_isdigit(**set))
			*set += 1;
	if(*(*set -1) && *(*set - 2) && *(*set -1) == '-' && *(*set - 2) == '.')
		nmbr_a[index2++] = '-';
	while (ft_isdigit(**set))
	{
		nmbr_a[index2++] = **set;
		*set += 1;
	}
}