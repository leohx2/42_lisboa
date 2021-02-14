/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <lrosendo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:04:56 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/14 16:04:56 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"

int main(int argc, char**argv)
{
    char c;
    if(argc != 2)
        return (0);
    int fd;
    fd = open(argv[1], O_RDWR | O_EXCL);
    while ((read(fd, &c, sizeof(char))) > 0)
    {}
    ft_putnbr_fd(-25555, fd);
    close(fd);
}
