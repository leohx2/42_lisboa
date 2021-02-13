/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:48:55 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:24:35 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen2(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
		cont++;
	return (cont);
}

char	*ft_strdup(const char *s)
{
	int		aux;
	char	*to_return;

	aux = 0;
	if (!(to_return = (char*)malloc(ft_strlen2(s) * sizeof(char))))
		return (0);
	while (s[aux])
	{
		to_return[aux] = s[aux];
		aux++;
	}
	to_return[aux] = '\0';
	return (to_return);
}
