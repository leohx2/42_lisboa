/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:36 by lrosendo          #+#    #+#             */
/*   Updated: 2022/02/10 22:11:20 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	error(int aux)
{
	if (aux == 0)
		ft_putstr_fd("Arguments error\n", 1);
	else if (aux == 1)
		ft_putstr_fd("wrong PID\n", 1);
	else
		ft_putstr_fd("Please, no arguments to launch the server\n", 1);
	return (1);
}
