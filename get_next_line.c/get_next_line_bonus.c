/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:43:14 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/08 12:22:59 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_saving(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

int	ft_value_return(char **save, char **line, int r, int fd)
{
	if (r < 0)
		return (-1);
	else if (r == 0 && save[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_saving(&save[fd], line));
}

int	get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	int			r;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(save[fd], buff);
			free(save[fd]);
			save[fd] = temp;
		}
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	return (ft_value_return(save, line, r, fd));
}