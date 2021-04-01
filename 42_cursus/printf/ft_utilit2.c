/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilit2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:43:23 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/01 18:27:23 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_is_null(char *set, char *str)//função para verificar se o caracter deve ou ser impresso
{
	int index;

	index = (int)ft_strlen(set) - 1;
	if (set[index] == '0' && set[index - 1] == '.' && (str[0] == 32 && !str[1])
	&& (!ft_isdigit(set[index - 2]) || !set[index - 2]))
		return (1);
	return (0);
}

int ft_dontprint(char *set, char *str, char *buffer, int i_main)
{
	int index;
	//printf("opa\n");
	index = (int)ft_strlen(set) - 1;
	if (str[0] == '0' && !str[1] && set[index] == '.' && 
	!ft_is_in_set(buffer[i_main], "sc"))
		str[0] = 32;
	return (1);
}

int	ft_help_dot(char *str, char *buffer, int i_main, int *helper,
	int *nmbr_int)
{
	if (!str)
		return (0);
	if ((str[0] == '0' && !str[1]) && (buffer[i_main - 1] == '0' &&
		!ft_isdigit(buffer[i_main - 2])))
	{
		str[0] = 32;
		return (0);
	}
	else if (str[0] == '-' && !ft_is_in_set(buffer[i_main], "sc"))
	{
		*helper += 1;
		*nmbr_int += 2;
		ft_putchar('-');
		return (1);
	}
	else if ((str[0] == '0' && !str[1]) && (buffer[i_main - 1] == '.' &&
		!ft_isdigit(buffer[i_main - 2])))
	{
		str[0] = 0;
		return (0);
	}
	return (0);
}

int	ft_rm_diff(int index2, char *nmbr_int1, char *str, char *buffer, int *index,
	int *i_main, char *set, int *confirm)
{
	if (set[*index - ft_strlen(nmbr_int1) - 2] == '-')
		*confirm = 1;

	if (!set[*index - 1] && !ft_is_in_set(buffer[*i_main], "sc") && *confirm == 0
		&& ft_isdigit(set[*index - 2]))
			return (ft_set_zd(set, index2, str, buffer, i_main, 'Z'));
	else if (!set[*index] && !ft_is_in_set(buffer[*i_main], "sc") && *confirm == 0)
		return (ft_set_zd(set, index2, str, buffer, i_main, 'D'));
	else if ((!set[*index] || set[*index] == '0') && 
		ft_is_in_set(buffer[*i_main], "sc") && *confirm == 0)
	{
		index2 += (int)ft_strlen(str);
		*index = (int)ft_strlen(set) + 1;
		str[0] = 0;
		return (ft_set_zd(set, index2, str, buffer, i_main, 'd'));
	}
	else if ((!set[*index] || set[*index] == '0') && 
		ft_is_in_set(buffer[*i_main], "sc") && *confirm == 1)
	{
		index2 += (int)ft_strlen(str);
		*index = (int)ft_strlen(set) + 1;
		str[0] = 0;
		return (ft_set_minus(index2, str, buffer, i_main, 0));
	}
	return (-1);
}