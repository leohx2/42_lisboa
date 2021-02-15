/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:22:42 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/15 14:01:19 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlen(const char *str)
{
	int	aux;

	aux = 0;
	while (str[aux])
		aux++;
	return (aux);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*to_return;
	int		aux;

	aux = ft_strlen(s1) + ft_strlen(s2);
	if (!(to_return = (char*)malloc(aux * sizeof(char))))
		return (0);
	aux = 0;
	while (*s1)
	{
		to_return[aux] = *s1;
		s1++;
		aux++;
		if (!(*s1))
		{
			while (*s2)
			{
				to_return[aux] = *s2;
				s2++;
				aux++;
			}
		}
	}
	to_return[aux] = '\0';
	return (to_return);
}
