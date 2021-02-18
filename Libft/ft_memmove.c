/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:58:35 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:19:14 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;
	char		*last_s1;
	const char	*last_s2;

	s1 = dest;
	s2 = src;
	if (s1 < s2)
	{
		while (n--)
			*s1++ = *s2++;
	}
	else
	{
		last_s1 = s1 + (n - 1);
		last_s2 = s2 + (n -1);
		while (n--)
			*last_s1-- = *last_s2--;
	}
	return (dest);
}
