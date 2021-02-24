/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:43:43 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/24 13:08:45 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main ()
{
	char **resultado = ft_split("Oi somos", ' ');
	int i = 0;
	while (resultado[i])
	{
		printf("\n%i CHECK\n", i);
		printf("%s\n", resultado[i]);
		i++;
	}
	while (i >= 0)
	{
		free(resultado[i]);
		printf("\n%i FREE\n", i);
		i--;
	}
	
	free(resultado);
}
