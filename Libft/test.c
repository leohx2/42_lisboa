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
    printf("%i\n", ft_strncmp("1234", "1235", 3));
    printf("%i\n", ft_strncmp("Tripouille", "TriPouille", 42));
    printf("%i\n", ft_strncmp("Tripouille", "TripouillE", 42));
    printf("%i\n", ft_strncmp("Tripouille", "Tripouill", 42));
}
