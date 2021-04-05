/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:58:24 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/05 18:58:24 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	ft_value(unsigned int n)
{
	long int	count;

	count = 1;
	while (n / count > 9)
		count *= 10;
	return (count);
}

static void		ft_make_str(long int nmbr_size, unsigned int n, 
			char *str_aux, int aux)
{
	while (nmbr_size >= 10)
	{
		str_aux[aux] = (n / nmbr_size) + 48;
		aux++;
		n = n % nmbr_size;
		nmbr_size /= 10;
	}
	if (n >= 10)
	{
		str_aux[aux] = (n / 10) + 48;
		aux++;
	}
	str_aux[aux] = (n % 10) + 48;
	aux++;
	str_aux[aux] = 0;
}

char			*ft_unsigned_itoa(unsigned int n)
{
	char		*to_return;
	char		*str_aux;
	int			aux;
	long int	nmbr_size;

	aux = 0;
	if (!(str_aux = (char*)malloc(12 * sizeof(char))))
		return (0);
	nmbr_size = ft_value(n);
	ft_make_str(nmbr_size, n, str_aux, aux);
	to_return = ft_strdup(str_aux);
	free(str_aux);
	return (to_return);
}