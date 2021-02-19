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
#include <string.h>
#include <fcntl.h>
#include "libft.h"

int     main()
{
    char	set [] = "\t \n";
    char *s1 = ft_strdup(" \n \t lorem ipsum dolor sit amet \n \n");
	printf("Resultado:\n**%s**\n", ft_strtrim(s1, set));
    free(s1);
    s1 = ft_strdup("LOURES ipsum dolor sit amet \n \t ");
    printf("Resultado:\n**%s**\n", ft_strtrim(s1, set));
    free(s1);
    s1 = ft_strdup("  \n  \t  LAURA \n ipsum \t dolor \n sit \t amet  \t \n ");
    printf("Resultado:\n**%s**\n", ft_strtrim(s1, set));
    free(s1);
}
