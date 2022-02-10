/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:58:22 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:18:00 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char aux;

	aux = c;
	while (n--)
	{
		if (*(unsigned char*)s == aux)
			return ((unsigned char*)s);
		s++;
	}
	return (0);
}
