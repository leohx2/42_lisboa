/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <lrosendo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:01:34 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/14 16:01:34 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, sizeof(char));
		s++;
	}
	write(fd, "\n", sizeof(char));
}
