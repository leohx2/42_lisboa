/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:43:43 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/31 21:29:31 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <string.h>
#define UINT_MAX  (__INT_MAX__  *2U +1U)
int main ()
{
	int len;

	len = ft_printf("%-11.2d.", -1);
	printf("\nRESULTADO FT:  %i", len);
	printf("\n---------------------------\n");
	len = printf("%-11.2d.", -1);
	printf("\nRESULTADO:     %i", len);

}

/*

*/