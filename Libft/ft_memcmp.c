/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:58:27 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/15 13:07:47 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_aux;
	unsigned char	*s2_aux;
	size_t		aux;

	aux = 0;
	s1_aux = (unsigned char*)s1;
	s2_aux = (unsigned char*)s2;
	while (aux < n)
	{
		if (s1_aux[aux] != s2_aux[aux])
			return (s1_aux[aux] - s2_aux[aux]);
		aux++;
	}
	return (0);
}
