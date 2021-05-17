/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:58:54 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:15:14 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int aux;

	aux = 0;
	while (s[aux])
	{
		if (s[aux] == (char)c)
			return ((char*)(s + aux));
		aux++;
	}
	if (s[aux] == (char)c)
		return ((char*)(s + aux));
	return (NULL);
}
