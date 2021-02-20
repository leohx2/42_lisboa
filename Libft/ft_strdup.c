/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:48:55 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/20 17:00:47 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s)
{
	int		aux;
	char	*to_return;

	aux = 0;
	if (!(to_return = (char*)ft_calloc(ft_strlen((char*)s) + 1, sizeof(char))))
		return (0);
	ft_memcpy(to_return, s, ft_strlen((char*)s));
	return (to_return);
}
