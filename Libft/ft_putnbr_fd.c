/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:53:40 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/15 18:58:31 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_size10(int n)
{
	int count;

	count = 1;
	while (n > 9)
	{
		count *= 10;
		n /= 10;
	}
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		size;
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", (sizeof(char) * 11));
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", sizeof(char));
		}
		size = ft_size10(n);
		while (n > 9)
		{
			c = (n / size) + 48;
			write(fd, &c, sizeof(char));
			n = n % size;
			size /= 10;
		}
		c = n + 48;
		write(fd, &c, sizeof(char));
	}
}
