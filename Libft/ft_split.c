/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:15:24 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/15 18:51:09 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int		ft_is_in_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static void		ft_final_part(char **str_return, char *str, char charset)
{
	int	aloc;
	int	count;
	int index;

	index = 0;
	aloc = 0;
	count = 0;
	while (str[index])
	{
		if (ft_is_in_charset(str[index], charset) == 0)
		{
			while (ft_is_in_charset(str[index], charset) == 0 && str[index])
			{
				str_return[aloc][count] = str[index];
				count++;
				if (!str[index + 1])
					break ;
				index++;
			}
			str_return[aloc][count] = 0;
			aloc++;
			count = 0;
		}
		index++;
	}
	str_return[aloc] = 0;
}

static void		ft_scnd_size(char **str_return, char *str, char charset)
{
	int	count;
	int	aloc;
	int index;

	index = 0;
	aloc = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (ft_is_in_charset(str[index], charset) == 0)
		{
			while (ft_is_in_charset(str[index], charset) == 0 && str[index])
			{
				count++;
				index++;
			}
			str_return[aloc] = (char*)malloc(count * sizeof(char));
			aloc++;
			count = 0;
		}
		index++;
	}
}

static int		ft_frst_size(char *str, char charset)
{
	int	size;
	int	index;
	int	aux;

	aux = 0;
	index = 0;
	size = 0;
	while (str[index] != '\0')
	{
		if (ft_is_in_charset(str[index], charset) == 0)
			aux++;
		if (ft_is_in_charset(str[index], charset) == 1)
		{
			if (aux > 0 && str[index + 1] != '\0' &&
			ft_is_in_charset(str[index + 1], charset) == 0)
			{
				while (ft_is_in_charset(str[index], charset) == 0
				&& str[index + 1] != '\0')
					index++;
				size++;
			}
		}
		index++;
	}
	return (size + 2);
}

char			**ft_split(char const *s, char c)
{
	char	**str_return;
	int		first_size;

	first_size = ft_frst_size((char*)s, c);
	str_return = (char**)malloc(sizeof(char *) * first_size);
	ft_scnd_size(str_return, (char*)s, c);
	ft_final_part(str_return, (char*)s, c);
	return (str_return);
}
