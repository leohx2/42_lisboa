/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:10:18 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/31 19:11:48 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}
