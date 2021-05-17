/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:58:47 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:19:27 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	aux;

	aux = 0;
	while (aux < n)
	{
		*(unsigned char*)(s + aux) = (unsigned char)c;
		aux++;
	}
	return (s);
}
