/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilit2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:43:23 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 09:53:43 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_is_null(set_str *set)//função para verificar se o caracter deve ou ser impresso
{
	if (*(set->set - 1) == '0' && *(set->set - 2) == '.' && (set->str[0] == 32 && !set->str[1])
		&& (!ft_isdigit(*(set->set - 3)) || !*(set->set - 3)))
		return (1);
	if (*(set->set - 1) == '0' && *(set->set - 2) == '.' && (set->str[0] == 32 && !set->str[1])
		&& (*(set->set - 3) == '0'))
		return (1);
	return (0);
}

int ft_dontprint(set_str *set)
{
	if (set->str[0] == '0' && !set->str[1] && *(set->set - 1) == '.' && 
		!ft_is_in_set(*set->buffer, "sc"))
		set->str[0] = 32;
	if (set->str[0] == '0' && !set->str[1] && *(set->set - 1) == '0'
		&& !ft_is_in_set(*set->buffer, "sc") && *(set->set - 2) == '.')
		set->str[0] = 32;
	return (1);
}

int	ft_help_dot(set_str *set, int *helper, int *nmbr_int)
{
	if (!set->str)
		return (0);
	if ((set->str[0] == '0' && !set->str[1])
		&& (*(set->buffer - 1) == '0' && !ft_isdigit(*(set->buffer - 2))))
	{
		set->str[0] = 32;
		return (0);
	}
	else if (set->str[0] == '-' && !ft_is_in_set(*set->buffer, "sc"))
	{
		*helper += 1;
		*nmbr_int += 2;
		ft_putchar('-');
		return (1);
	}
	else if ((set->str[0] == '0' && !set->str[1]) && (*(set->buffer - 1) == '.'
		&& !ft_isdigit(*(set->buffer - 2))))
	{
		set->str[0] = 0;
		return (0);
	}
	return (0);
}

int	ft_rm_diff(int index2, set_str *set)
{
	int	confirm;

	confirm = isit_negative(set->set);
	if (!*(set->set - 1) && !ft_is_in_set(*set->buffer, "sc") && confirm == 0
		&& ft_isdigit(*(set->set - 2)))
			return (ft_set_zd(index2, set, 'Z'));
	else if (!*set->set && !ft_is_in_set(*set->buffer, "sc") && confirm == 0)
		return (ft_set_zd(index2, set, 'D'));
	else if ((!*set->set || *set->set == '0') && 
		ft_is_in_set(*set->buffer, "sc") && confirm == 0)
	{
		index2 += (int)ft_strlen(set->str);
		set->set += (int)ft_strlen(set->set);
		set->str[0] = 0;
		return (ft_set_zd(index2, set, 'd'));
	}
	else if ((!*set->set || *set->set == '0') && 
		ft_is_in_set(*set->buffer, "sc") && confirm == 1)
	{
		index2 += (int)ft_strlen(set->str);
		set->set += (int)ft_strlen(set->set);
		set->str[0] = 0;
		return (ft_set_minus(index2, set, 0));
	}
	return (-1);
}

int	ft_index2(set_str *set, char *n1, char *n2)
{
	int index2;

	if (*set->buffer == 's' && (int)ft_strlen(set->str) < ft_atoi(n2))//from here
		index2 = ft_atoi(n1) - ft_strlen(set->str); 
	else if (ft_atoi(n2) == 0)
		index2 = ft_atoi(n1) - (int)ft_strlen(set->str);
	else if ((int)ft_strlen(set->str) > ft_atoi(n2)
		&& !ft_is_in_set(*set->buffer, "sc"))//verificar em caso de %c ou %d
		index2 = ft_atoi(n1) - ft_strlen(set->str);
	else if (ft_atoi(n2) < 0)
		index2 = ft_atoi(n1) - ft_strlen(set->str);
	else
		index2 = ft_atoi(n1) - ft_atoi(n2); 
	if (set->str[0] == '-' && ft_atoi(n2) >= (int)ft_strlen(set->str))
		index2--;
	return (index2);
}

void	free_bird(char *buffer)
{
	while (*(buffer - 1))
		buffer--;
	free(buffer);
}

int	ft_rvlen(char *buffer)
{
	int	size;

	size = 0;
	while (*(--buffer))
		size++;
	return (size);
}

int	isit_negative(char *str)
{
	int index;

	index = -2;
	while (ft_isdigit(str[index]))
		index--;
	if (str[index] == '-')
		return (1);
	else
		return (0);
}
