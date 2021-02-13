/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:59:30 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:15:51 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	aux;
	int	to_return;

	aux = 0;
	to_return = 0;
	while (s[aux])
	{
		if (s[aux] == c)
			to_return = aux;
		aux++;
	}
	if (to_return > 0)
		return ((char*)(s + to_return));
	else
		return (0);
}
