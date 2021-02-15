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
#include <unistd.h>
#include "libft.h"

int     main()
{
    char **test;

    test = ft_split(" This is a test.", '8');
    printf("Comeca aqui\n%s\n%s\n", test[0],test[1]);
    free (test);
}
