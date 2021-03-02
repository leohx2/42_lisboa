/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:55:46 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/02 20:58:59 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	compare;

	compare = 0;
	if (!dest)
		return (0);
	while (compare < n && src)
	{
		*(char*)(dest + compare) = *(char*)(src + compare);
		compare++;
	}
	return (dest);
}

int		ft_havenew(char *s)
{
	int aux;

	aux = 0;
	if (!s)
		return (0);
	while (s[aux])
	{
		if (s[aux] == '\n')
			return (1);
		aux++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

char	*ft_strdup(const char *s)
{
	int		aux;
	char	*to_return;

	aux = 0;
	if (!(to_return = (char*)malloc(ft_strlen((char*)s) + 1 * sizeof(char))))
		return (0);
	to_return[ft_strlen((char*)s)] = 0;
	ft_memcpy(to_return, s, ft_strlen((char*)s));
	return (to_return);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*to_return;
	int		aux;
	int		len;
	int		aux2;

	aux2 = 0;
	aux = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(to_return = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	while (s1[aux])
	{
		to_return[aux] = s1[aux];
		aux++;
	}
	while (s2[aux2])
		to_return[aux++] = s2[aux2++];
	to_return[aux] = '\0';
	return (to_return);
}
