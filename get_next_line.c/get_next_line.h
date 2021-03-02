/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:38:00 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/02 20:22:05 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_havenew(char *s);