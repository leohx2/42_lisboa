/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:09:27 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 19:57:00 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (c == -1)
	{
		c = 0;
		write(1, &c, sizeof(char));
		return (1);
	}
	write(1, &c, sizeof(char));
	if (c != 0)
		return (1);
	else
		return (0);
}
