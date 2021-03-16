/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:43:43 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/16 13:29:37 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int main ()
{
	size_t Gb = 1024*1024*1024; // Falta encontrar uma solução para o %p
	char *a = (char *)malloc(2 * Gb * sizeof(char));
	char *b = (char *)malloc(2 * Gb * sizeof(char));
	ft_printf("ft_printf a = %p\n", a);
	ft_printf("ft_printf b = %p\n", b);
	printf("printf a = %p\n", a);
	printf("printf b = %p\n", b); 
	free(a);
	free(b);
}

