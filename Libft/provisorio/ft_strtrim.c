/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:14:31 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 19:39:22 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isset(char c, char const *set)
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

int		ft_strlen(const char *s1)
{
	int	count;

	count = 0;
	while (s1[count])
		count++;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*to_return;
	int		aux;

	aux = 0;
	to_return = (char*)malloc(ft_strlen(s1) * sizeof(char));
	while (*s1)
	{
		if (!(ft_isset(*s1, set)))
		{
			to_return[aux] = *s1;
			aux++;
		}
		s1++;
	}
	to_return[aux] = '\0';
	return (to_return);
}
