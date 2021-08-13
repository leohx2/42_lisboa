/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:49:22 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 20:23:51 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_aux;
	unsigned char	*s2_aux;
	size_t			aux;

	s1_aux = (unsigned char *)s1;
	s2_aux = (unsigned char *)s2;
	aux = 0;
	if (n == 0)
		return (0);
	if (!ft_strlen(s1) && ft_strlen(s2))
		return (-1);
	while (aux < n && s1_aux[aux] && s2_aux[aux])
	{
		if (s1_aux[aux] != s2_aux[aux])
			return (s1_aux[aux] - s2_aux[aux]);
		aux++;
	}
	if (s1_aux[aux] != s2_aux[aux] && aux < n)
		return (s1_aux[aux] - s2_aux[aux]);
	return (0);
}
