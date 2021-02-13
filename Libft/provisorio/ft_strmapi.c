/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:58:20 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 19:30:37 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*to_return;
	unsigned int	aux;
	unsigned int	s_len;

	s_len = ft_strlen((char*)s);
	aux = 0;
	if (!(to_return = (char*)malloc(s_len * sizeof(char))))
		return (0);
	while (s[aux])
	{
		to_return[aux] = f(1, s[aux]);
		aux++;
	}
	to_return[aux] = '\0';
	return (to_return);
}
