/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:57:27 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/24 12:47:04 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*to_return;
	size_t	to_alloc;

	to_alloc = size * n;
	to_return = malloc(to_alloc);
	if (!to_return)
		return (0);
	ft_bzero(to_return, to_alloc);
	return (to_return);
}
