/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:59:26 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/15 19:01:57 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t			aux;
	int				to_return;
	size_t			aux_d;

	aux_d = 0;
	aux = 0;
	while (dest[aux] && aux < len)
	{
		if (dest[aux] == src[aux_d])
		{
			aux_d = 0;
			while (dest[aux + aux_d] == src[aux_d]
			&& (aux_d + aux) < len)
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
