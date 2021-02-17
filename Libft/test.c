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

int     main()
{
    t_list  *test2 = NULL;

    test2 = ft_lstnew((void*)0);
    printf("%i\n", test2->content);
	ft_lstadd_front(&test2, ft_lstnew((void*)1));
    printf("%i\n", test2->content);
	ft_lstadd_front(&test2, ft_lstnew((void*)2));
    printf("%i\n", test2->content);
    printf("%i  SIZE\n%i   LAST\n", ft_lstsize(test2), ft_lstlast(test2)->content);
    free(test2);
}
