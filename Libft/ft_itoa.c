/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:10:41 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/15 18:57:29 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_value(int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{	
		count *= 10;
		n /= 10;
	}
	return (count);
}

static void		ft_make_str(int nmbr_size, int n, char *str_aux, int aux)
{
	while (nmbr_size > 1 && n > 9)
	{
		str_aux[aux++] = (n / nmbr_size) + 48;
		n = n % nmbr_size;
		nmbr_size /= 10;
	}
	str_aux[aux++] = (n % 10) + 48;
	str_aux[aux++] = 0;
}

char			*ft_itoa(int n)
{
	char	*to_return;
	char	*str_aux;
	int		aux;
	int		nmbr_size;

	aux = 0;
	if (!(str_aux = (char*)malloc(12 * sizeof(char))))
		return (0);
	if (n == -2147483648)
		return (str_aux = "-2147483648\0");
	if (n < 0)
	{
		str_aux[aux++] = '-';
		n *= -1;
	}
	nmbr_size = ft_value(n);
	ft_make_str(nmbr_size, n, str_aux, aux);
	to_return = (char*)ft_calloc(sizeof(char), ft_strlen(str_aux));
	ft_memcpy(to_return, str_aux, ft_strlen(str_aux));
	to_return[ft_strlen(to_return)] = '\0';
	return (to_return);
}
