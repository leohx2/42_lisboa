/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:28:19 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/23 18:37:27 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
unsigned int len)
{
	char			*str_aux;
	unsigned int	aux;
	int				alloc;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len + start)
		alloc = ft_strlen(s) - start;
	else
		alloc = len;
	if (ft_strlen(s) < start || len == 0)
		return (str_aux = (char*)ft_calloc(2, 1));
	if (!(str_aux = (char*)ft_calloc(alloc + 1, sizeof(char))))
		return (NULL);
	aux = 0;
	while (aux < len && s[start])
	{
		str_aux[aux] = s[start];
		start++;
		aux++;
	}
	return (str_aux);
}
