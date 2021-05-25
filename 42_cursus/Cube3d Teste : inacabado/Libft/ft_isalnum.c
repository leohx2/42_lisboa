/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:47:16 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 18:14:27 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c > 47 && c < 58)
		return (4);
	else if (c > 96 && c < 123)
		return (2);
	else if (c > 64 && c < 91)
		return (1);
	else
		return (0);
}