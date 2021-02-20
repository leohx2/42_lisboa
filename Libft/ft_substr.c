/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:28:19 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/20 15:14:44 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
unsigned int len)
{
	char				*str_aux;
	char				*to_return;
	unsigned int		aux;

	if (ft_strlen(s) < start)
		return (to_return = (char*)ft_calloc(2, 1));
	str_aux = (char*)malloc((len - start + 1) * sizeof(char));
	aux = 0;
	while (aux < len && s[start])
	{
		str_aux[aux] = s[start];
		start++;
		aux++;
	}
	str_aux[aux] = 0;
	to_return = (char*)malloc((ft_strlen(str_aux) * sizeof(char)));
	ft_memcpy(to_return, str_aux, ft_strlen(str_aux));
	to_return[aux] = 0;
	free(str_aux);
	return (to_return);
}
