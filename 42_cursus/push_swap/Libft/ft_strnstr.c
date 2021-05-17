/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:59:26 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/20 16:07:02 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t			aux;
	size_t			aux_d;

	aux_d = 0;
	aux = 0;
	if (*src == 0)
		return ((char*)dest);
	while (dest[aux] && aux < len)
	{
		aux_d = 0;
		if (dest[aux] == src[aux_d])
		{
			while (dest[aux + aux_d] == src[aux_d]
			&& (aux + aux_d) < len)
			{
				if (src[aux_d + 1] == '\0')
					return ((char*)(dest + aux));
				aux_d++;
			}
		}
		aux++;
	}
	return (0);
}
