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

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*to_return;
	int		aux;
	int		len;

	aux = 0;
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(to_return = (char*)malloc(len * sizeof(char))))
		return (0);
	ft_memcpy(to_return, s1, ft_strlen((char*)s1));
	while (s2[aux])
	{
		to_return[aux + ft_strlen((char*)s1)] = s2[aux];
		aux++;
	}
	to_return[len] = '\0';
	return (to_return);
}
