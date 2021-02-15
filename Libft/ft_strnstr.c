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

static int		ft_confirm(const char *dest, const char *src, size_t aux)
{
	int	aux2;

	aux2 = 0;
	while (src[aux2])
	{
		if (src[aux2] != dest[aux])
			return (0);
		aux++;
		aux2++;
	}
	return (1);
}

char			*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t			aux;
	int				to_return;

	aux = 0;
	to_return = 0;
	while (dest[aux] && aux < len)
	{
		if (dest[aux] == src[0])
		{
			to_return = ft_confirm(dest, src, aux);
			if (to_return == 1)
				return ((char*)(dest + aux));
		}
		aux++;
	}
	return (0);
}
