/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:43:43 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/25 17:21:03 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int main ()
{// arrumar o ft_is_last para saber quando devo adcionar a precision
	int a = 0;

	ft_printf("STR%-5.3s.\n", "string");
	printf("STR%-5.3s.\n", "string");
	ft_printf("INT%-5.4d.\n", 42);
	printf("INT%-5.4d.\n", 42);
}
