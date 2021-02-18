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
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (s)
	{
		if (*(char*)s == (char)c)
			return ((char*)s);
		s++;
		if (*(char*)s == (char)c)
			return ((char*)s);
	}
	return (0);
}
