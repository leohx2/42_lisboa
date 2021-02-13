/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:49:22 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:19:54 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			aux;
	int				s1_value;
	int				s2_value;

	aux = 0;
	s1_value = *s1;
	s2_value = *s2;
	while (*s1 == *s2 && *s1 && aux < n)
	{
		s1_value += *s1;
		s2_value += *s2;
		s1++;
		s2++;
		if (!*s1 && *s2)
			s2_value += 1;
		if (!*s2 && *s1)
			s1_value += 1;
		aux++;
	}
	if (*s2 && *s1)
	{
		s1_value += *s1;
		s2_value += *s2;
	}
	return (s1_value - s2_value);
}
