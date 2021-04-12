/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:14:31 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 20:26:02 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	aux;

	aux = 0;
	while (set[aux])
	{
		if (c == set[aux])
			return (1);
		aux++;
	}
	return (0);
}

static int	ft_begin(char const *c, char const *set)
{
	int	aux;

	aux = 0;
	while (c[aux] && ft_isset((char)c[aux], set))
		aux++;
	return (aux);
}

int	ft_islast(char const *s1, char const *set, int index)
{
	while (s1[index] && ft_isset((char)s1[index], set))
	{
		index++;
		if (s1[index] == 0)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		aux;
	int		aux2;
	char	*to_return;

	if (!s1)
		return (NULL);
	aux = ft_begin(s1, set);
	aux2 = aux;
	while (s1[aux2])
	{
		if (ft_isset((char)s1[aux2], set) && ft_islast(s1, set, aux2))
		{
			to_return = (char *)ft_calloc((aux2 - aux + 1), sizeof(char));
			ft_memcpy(to_return, (s1 + aux), (aux2 - aux));
			return (to_return);
		}
		aux2++;
	}
	to_return = ft_strdup((char *)(s1 + aux));
	return (to_return);
}
