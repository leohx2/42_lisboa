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
	size_t			aux;
	int				temp[size * n];

	temp[0] = 0;
	aux = 0;
	to_alloc = size * n;
	if (n == 0 || size == 0)
		return (0);
	if (!(to_return = malloc(to_alloc)))
		return (0);
	while (aux < to_alloc)
	{
		temp[aux] = 0;
		aux++;
	}
	to_return = temp;
	return (to_return);
}
