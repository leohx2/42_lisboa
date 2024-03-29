/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:58:20 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 20:23:27 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*to_return;
	unsigned int	aux;
	unsigned int	s_len;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen((char *)s);
	aux = 0;
	to_return = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (!(to_return))
		return (0);
	while (s[aux])
	{
		to_return[aux] = (*f)(aux, s[aux]);
		aux++;
	}
	return (to_return);
}
