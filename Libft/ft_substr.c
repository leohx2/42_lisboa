/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:28:19 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/20 17:38:04 by lrosendo         ###   ########.fr       */
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
	if(!(str_aux = (char*)ft_calloc((len - start + 2), sizeof(char))))
		return(NULL);
	aux = 0;
	while (aux < len && s[start])
	{
		str_aux[aux] = s[start];
		start++;
		aux++;
	}
	str_aux[aux] = 0;
	to_return = ft_strdup(str_aux);
	free(str_aux);
	return (to_return);
}
