/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:48:01 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/24 13:09:03 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int		ft_isset(char *s, char c)
{
	int count;
	int aux;
	int aux2;

	aux2 = 0;
	aux = 0;
	count = 0;
	while (s[count])
	{
		if (s[count] == c && s[count + 1] != c && s[count + 1] && aux2 > 0)
			aux++;
		else if (s[count] != c)
			aux2++;
		count++;
	}
	if (aux == 0 && aux2 > 0)
		return (2);
	if (aux == 0 && aux2 == 0)
		return (1);
	else
		return (aux + 2);
}

void	ft_set_mem(char **to_return, int size, char *s, char c)
{
	int start;
	int end;
	int aux;

	aux = 0;
	start = 0;
	end = 0;
	while (s[start] && aux < size)
	{
		end = 0;
		if (s[start] != c)
		{
			while (s[start + end] != c && s[start + end])
				end++;
			to_return[aux] = ft_substr(s, start, end);
			aux++;
			start += end;
		}
		if (s[start])
			start++;
	}
}

char	**ft_split(char const *s, char c)
{
	char **to_return;
	int aux;

	aux = 0;
	if (!s)
		return (NULL);
	to_return = (char**)ft_calloc(ft_isset((char*)s, c), sizeof(char*));
	if(!to_return)
		return (NULL);
	if (ft_isset((char*)s, c) == 1)
		return (to_return);
	ft_set_mem(to_return, ft_isset((char*)s, c), (char*)s, c);
	return (to_return);
}