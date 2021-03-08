/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:43:14 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/08 10:35:57 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	ft_memcpy(temp, str, index);
	temp[index] = 0;
	return (temp);
}

char	*ft_afternew(char *str)
{
	int 	index;
	char	*temp;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (!str[index] || !str[index + 1])
	{
		free(str);
		return (NULL);
	}
	index++;
	temp = ft_strdup(str + index);
	free(str);
	return(temp);
}

void	ft_set_loop(char *buff, char **save, int fd, int *r)
{
	char *test;
	
	while (!ft_havenew(save[fd]) && *r != 0)
	{
		if ((*r = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return ;
		}
		buff[*r] = '\0';
		test = ft_strjoin(save[fd], buff);
		free (save[fd]);
		save[fd] = ft_strdup(test);
		free(test);
	}
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
	if (!save[fd])
		save[fd] = malloc(sizeof(char) * BUFFER_SIZE);
	ft_set_loop(buff, save, fd, &r);
	if (r == -1)
		return (-1);
	free(buff);
	*line = ft_befornew(save[fd]);
	save[fd] = ft_afternew(save[fd]);
	if (r == 0)
		return (0);
	return (1);
}