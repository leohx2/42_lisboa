/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:14:31 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/15 13:16:25 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isset(char c, char const *set)
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

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*to_return;
	int		aux;
	char	*str_aux;

	aux = 0;
	str_aux = (char*)malloc(ft_strlen(s1) * sizeof(char));
	while (*s1)
	{
		if (!(ft_isset(*s1, set)))
		{
			str_aux[aux] = *s1;
			aux++;
		}
		s1++;
	}
	to_return = (char*)ft_calloc(sizeof(char), ft_strlen(str_aux));
	ft_memcpy(to_return, str_aux, ft_strlen(str_aux));
	free(str_aux);
	to_return[aux] = '\0';
	return (to_return);
}
