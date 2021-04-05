/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:43:43 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/05 18:34:36 by lrosendo         ###   ########.fr       */
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
	int len;
	
	len = ft_printf("%--*.*i", -6, -3,-3);
	printf("\nRESULTADO FT:  %i", len);
	printf("\n---------------------------\n");
	len = printf("%--*.*i", -6, -3,-3);
	printf("\nRESULTADO FT:  %i", len);
	printf("\n---------------------------\n");
}
/*
("%% *.5i 42 == |% *.5i|", 4, 42)
First line of code: {return test("%.*i", -6, -3);}
*/