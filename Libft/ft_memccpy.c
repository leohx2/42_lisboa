/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:58:16 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/15 20:34:43 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	aux;

	aux = 0;
	if ( n == 0)
		return (NULL);
	while (aux < n)
	{
		*(char*)(dest + aux) = *(char*)(src + aux);
		if (*(char*)(dest + aux) == c)
			return (dest + aux + 1);
		aux++;
	}
	return (0);
}
