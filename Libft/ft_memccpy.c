/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:58:16 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:17:47 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	aux;

	aux = 0;
	while (*(char*)src != '\0' && aux < n)
	{
		*(char*)dest = *(char*)src;
		dest++;
		src++;
		if (*(char*)(dest - 1) == c)
			return (dest);
		aux++;
	}
	*(char*)dest = 0;
	return (0);
}
