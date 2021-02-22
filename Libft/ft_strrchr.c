/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:59:30 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/22 16:30:17 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	aux;
	int	to_return;

	aux = 0;
	to_return = -1;
	while (s[aux])
	{
		if (s[aux] == (char)c)
			to_return = aux;
		aux++;
	}
	if (s[aux] == (char)c)
		to_return = aux;
	if (to_return == -1)
		return (0);
	return ((char*)(s + to_return));
}
