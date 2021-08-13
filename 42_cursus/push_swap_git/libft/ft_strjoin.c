/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:22:42 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 20:22:31 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*to_return;
	int		aux;
	int		len;

	aux = 0;
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	to_return = (char *)malloc(len * sizeof(char));
	if (!(to_return))
		return (0);
	ft_memcpy(to_return, s1, ft_strlen((char *)s1));
	while (s2[aux])
	{
		to_return[aux + ft_strlen((char *)s1)] = s2[aux];
		aux++;
	}
	to_return[len] = '\0';
	return (to_return);
}
