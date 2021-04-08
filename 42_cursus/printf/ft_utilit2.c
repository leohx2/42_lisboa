/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilit2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:43:23 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/08 23:06:25 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_is_null(char **set, char *str)//função para verificar se o caracter deve ou ser impresso
{
	if (*(*set - 1) == '0' && *(*set - 2) == '.' && (str[0] == 32 && !str[1])
	&& (!ft_isdigit(*(*set - 3)) || !*(*set - 3)))
		return (1);
	return (0);
}

int ft_dontprint(char **set, char *str, char **buffer)
{
	if (str[0] == '0' && !str[1] && *(*set - 1) == '.' && 
	!ft_is_in_set(**buffer, "sc"))
		str[0] = 32;
	return (1);
}

int	ft_help_dot(char *str, char **buffer, int *helper, int *nmbr_int)
{
	if (!str)
		return (0);
	if ((str[0] == '0' && !str[1])
		&& (*(*buffer - 1) == '0' && !ft_isdigit(*(*buffer - 2))))
	{
		str[0] = 32;
		return (0);
	}
	else if (str[0] == '-' && !ft_is_in_set(**buffer, "sc"))
	{
		*helper += 1;
		*nmbr_int += 2;
		ft_putchar('-');
		return (1);
	}
	else if ((str[0] == '0' && !str[1]) && (*(*buffer - 1) == '.' &&
		!ft_isdigit(*(*buffer - 2))))
	{
		str[0] = 0;
		return (0);
	}
	return (0);
}

int	ft_rm_diff(int index2, char *nmbr_int1, char *str, char **buffer, char **set, int *confirm)
{
	if (*(*set - ft_strlen(nmbr_int1) - 2) == '-')
		*confirm = 1;
	if (!*(*set - 1) && !ft_is_in_set(**buffer, "sc") && *confirm == 0
		&& ft_isdigit(*(*set - 2)))
			return (ft_set_zd(set, index2, str, buffer, 'Z'));
	else if (!**set && !ft_is_in_set(**buffer, "sc") && *confirm == 0)
		return (ft_set_zd(set, index2, str, buffer, 'D'));
	else if ((!**set || **set == '0') && 
		ft_is_in_set(**buffer, "sc") && *confirm == 0)
	{
		index2 += (int)ft_strlen(str);
		*set += (int)ft_strlen(*set);
		str[0] = 0;
		return (ft_set_zd(set, index2, str, buffer, 'd'));
	}
	else if ((!**set || **set == '0') && 
		ft_is_in_set(**buffer, "sc") && *confirm == 1)
	{
		index2 += (int)ft_strlen(str);
		*set += (int)ft_strlen(*set);
		str[0] = 0;
		return (ft_set_minus(index2, str, buffer, 0));
	}
	return (-1);
}

int	ft_index2(char **buffer, char *str, char *n1, char *n2)
{
	int index2;

	if (**buffer == 's' && (int)ft_strlen(str) < ft_atoi(n2))//from here
		index2 = ft_atoi(n1) - ft_strlen(str); 
	else if (ft_atoi(n2) == 0)
		index2 = ft_atoi(n1) - (int)ft_strlen(str);
	else if ((int)ft_strlen(str) > ft_atoi(n2) && !ft_is_in_set(**buffer, "sc"))//verificar em caso de %c ou %d
		index2 = ft_atoi(n1) - ft_strlen(str);
	else if (ft_atoi(n2) < 0)
		index2 = ft_atoi(n1) - ft_strlen(str);
	else
		index2 = ft_atoi(n1) - ft_atoi(n2); 
	if (str[0] == '-' && ft_atoi(n2) >= (int)ft_strlen(str))
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
