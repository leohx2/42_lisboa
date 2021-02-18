/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:04:56 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/15 18:55:10 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include <string.h>


int main(void)
{
	t_list * l =  ft_lstnew(malloc(1));

    printf("ft_lstclear:\n");
	for (int i = 0; i < 10; ++i)
		ft_lstadd_front(&l, ft_lstnew(malloc(1)));
	ft_lstclear(&l, free);
	if(l == 0)
        printf("Passou do 1\n");
	/* 2 All other checks are done by valgrind */
	write(1, "\n", 1);
	return (0);
}
