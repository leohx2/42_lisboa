/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:48:33 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 19:07:14 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	compare;

	compare = 0;
	if (!dest)
		return (dest);
	while (compare < n && src)
	{
		*(char*)(dest + compare) = *(char*)(src + compare);
		compare++;
	}
	return (dest);
}
