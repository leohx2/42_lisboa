/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:43:14 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/02 21:05:20 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_befornew(char *str)
{
	int		index;
	char	*temp;

	if (!str)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	temp = (char*)malloc(sizeof(char) * (index + 1));
	if (!temp)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != '\n')
	{
		temp[index] = str[index];
		index++;
	}
	temp[index] = 0;
	return (temp);
}

char	*ft_afternew(char *str)
{
	int 	index;
	char	*temp;
	int		index_temp;

	index_temp = 0;
	index = 0;
	if (!str)
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (0);
	}
	temp = (char*)malloc(sizeof(char) * (ft_strlen(str) - index + 1));
	if (!temp)
		return (NULL);
	index++;
	while (str[index])
		temp[index_temp++] = str[index++];
	temp[index_temp] = 0;
	free(str);
	return (temp);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[4096];
	int			r;
	char		*buff;

	if ((read(fd, 0, 0) < 0) || BUFFER_SIZE <= 0 || !line )
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	r = 1;
	while (!ft_havenew(save[fd]) && r != 0)
	{
		if ((r = read(fd, buff, BUFFER_SIZE)) < 0)
		{
			free(buff);
			return (-1);
		}
		buff[r] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	free(buff);
	*line = ft_befornew(save[fd]);
	save[fd] = ft_afternew(save[fd]);
	if (r == 0)
		return (0);
	return (1);
}