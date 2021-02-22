/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:04:56 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/22 14:25:54 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"
#include <unistd.h>

int     main(int argc, char **argv)
{
	int		fd;
	char	c;
	int		i;

	i = 1;
	fd = open(argv[1], O_RDWR);
	while (i <= 1000000000)
	{
		while ((read(fd, &c, sizeof(char))) > 0)
		{}
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(i, fd);
		i *= 11;
	}
}