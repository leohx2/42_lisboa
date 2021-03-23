/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:43:43 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/23 01:19:37 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int main ()
{// arrumar o ft_is_last para saber quando devo adcionar a precision
	int a = 0;

	ft_printf("%03.d. .%04.3d\n", 1, 2);//verificar o pq esta dando segmentation Fault
	printf("%-3d. .%04.3d\n", 1, 2);
}
