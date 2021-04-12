/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:53:40 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 20:18:18 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_size10(int n)
{
	int	count;

	count = 1;
	while (n / count > 9)
		count *= 10;
	return (count);
}

static void	ft_putfd(int size, int fd, int n)
{
	char	c;

	while (size >= 10)
	{
		c = (n / size) + 48;
		write(fd, &c, sizeof(char));
		n = n % size;
		size /= 10;
	}
	if (n >= 10)
	{
		c = (n / 10) + 48;
		write(fd, &c, sizeof(char));
	}
	c = n + 48;
	write(fd, &c, sizeof(char));
}

void	ft_putnbr_fd(int n, int fd)
{
	int		size;

	if (n == -2147483648)
		write(fd, "-2147483648", (sizeof(char) * 11));
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", sizeof(char));
		}
		size = ft_size10(n);
		ft_putfd(size, fd, n);
	}
}
