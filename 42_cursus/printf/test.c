/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:43:43 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/01 21:05:06 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <string.h>
#define UINT_MAX  (__INT_MAX__  *2U +1U)
#define INT_MIN   (-__INT_MAX__  -1)
#define SCHAR_MIN (-__SCHAR_MAX__-1)
#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX __SCHAR_MAX__xw
#define LONG_MAX  __LONG_MAX__
#define LONG_MIN  (-__LONG_MAX__ -1L)
int main ()
{
	int len;
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	len = ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d);
	printf("\nRESULTADO FT:  %i", len);
	printf("\n---------------------------\n");
	len = printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d);
	printf("\nRESULTADO FT:  %i", len);
	printf("\n---------------------------\n");
	//printf("\n---------------------------\n");
}
/*
	TEST(16, print("%.4s%.s", "12345", "12345"));
	TEST(17, print("%10.4s%.5s", "12345", "12345"));	
*/