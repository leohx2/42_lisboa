/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:59:08 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 20:22:54 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	to_return;
	size_t	index;
	size_t	dst_size;
	size_t	src_size;

	dst_size = ft_len(dst);
	src_size = ft_len(src);
	index = dst_size;
	if (dst_size >= size)
		return (size + src_size);
	else
		to_return = dst_size + src_size;
	while (index + 1 < size && src[index - dst_size])
	{
		dst[index] = src[index - dst_size];
		index++;
	}
	dst[index] = '\0';
	return (to_return);
}
