/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:43:43 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/24 16:52:54 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main ()
{
	char **resultado = ft_split("Oi somos pai e filho", ' ');
	int i = 0;
	while (resultado[i])
	{
		printf("%s\n", resultado[i]);
		i++;
	}
	while (i >= 0)
	{
		free(resultado[i]);
		i--;
	}
	
	free(resultado);
}
