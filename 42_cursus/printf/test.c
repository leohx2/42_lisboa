/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:43:43 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/30 17:41:05 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int main ()
{// arrumar o ft_is_last para saber quando devo adcionar a precision
	
	ft_printf("%*c\n", 1, '0');
	// arrumar os returns das paradas
}
//	TEST(8, print("%*c", 1, '0'));
//	TEST(10, print("%*c", 2, '0'));
//	TEST(11, print("%*c", -2, '0'));
//	TEST(13, print("%*c", 10, '0'));
//	TEST(14, print("%*c", -10, '0'));
//	TEST(15, print("%*c%*c", -10, '0', 10, '1'));
//	TEST(16, print("*%c%*c", '0', 10, '1'));
//	TEST(17, print("%*c%c*", -10, '0', '1'));
