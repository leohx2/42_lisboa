/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:01:28 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/01 22:52:18 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main ()
{
{
  char  *line;
  int   fd1;
  int   fd2;

  fd1 = open("text.txt", O_RDONLY);
  fd2 = open("text2.txt", O_RDONLY);

  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  return (0);
}
}

