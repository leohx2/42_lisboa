/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:49:22 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:19:54 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*s1_aux;
	char	*s2_aux;
	size_t	aux;

	s1_aux = (char*)s1;
	s2_aux = (char*)s2;
	aux = 0;
	if (n == 0)
		return (0);
	while (aux < n)
	{
		if (s1_aux[aux] != s2_aux[aux])
			return (s1_aux[aux] - s2_aux[aux]);
		aux++;
	}
	return (0);
}
