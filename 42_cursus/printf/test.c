/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:43:43 by lrosendo          #+#    #+#             */
/*   Updated: 2021/03/30 16:41:48 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int main ()
{// arrumar o ft_is_last para saber quando devo adcionar a precision
	int len;

	len = ft_printf("%-3.2s. %10.42d\n", "o", -10);
	ft_printf("RESULTADO FT 1: %i\n", len);
	len = printf("%-3.2s. %10.42d\n", "o", -10);
	ft_printf("RESULTADO    1: %i\n", len);
	/*
	len = ft_printf("--0*%0*.0d*0 0*%0*.10d*0--\n", -2, 0, 21, 1);
	ft_printf("RESULTADO FT 2: %i\n", len);
    len = printf("--0*%0*.0d*0 0*%0*.10d*0--\n", -2, 0, 21, 1);
	ft_printf("RESULTADO    2: %i\n", len);
	len = ft_printf("%0.5d.\n", -10);
	ft_printf("RESULTADO FT 3: %i\n", len);
	len = printf("%0.5d.\n", -10);
	ft_printf("RESULTADO    3: %i\n", len);
	len = ft_printf(".%0*.*d.\n",12, 10, -101);
	ft_printf("RESULTADO FT 4: %i\n", len);
	len = printf(".%0*.*d.\n",12, 10, -101);
	ft_printf("RESULTADO    4: %i\n", len);
	*/
	// arrumar os returns das paradas
}
