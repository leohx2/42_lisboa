/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:57:27 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:17:26 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void			*to_return;
	size_t			to_alloc;

	to_alloc = size * n;
	if (!(to_return = malloc(to_alloc)))
		return (0);
	ft_memset(to_return, 0, size);
	return (to_return);
}
