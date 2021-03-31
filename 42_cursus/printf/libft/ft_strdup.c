/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:48:55 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/31 19:45:37 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			*ft_strdup(const char *s)
{
	int		aux;
	char	*to_return;

	if (s == NULL)
	{
		if (!(to_return = (char*)ft_calloc(7, sizeof(char))))
			return (0);
		ft_memcpy(to_return, "(null)", 7);
		return (to_return);	
	}
	aux = 0;
	if (!(to_return = (char*)ft_calloc(ft_strlen((char*)s) + 1, sizeof(char))))
		return (0);
	ft_memcpy(to_return, s, ft_strlen((char*)s));
	return (to_return);
}
