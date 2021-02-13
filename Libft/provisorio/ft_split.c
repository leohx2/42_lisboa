/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:15:24 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/13 19:37:25 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_in_charset(char c, char *charset)
{
	int index;

	index = 0;
	while (charset[index] != '\0')
	{
		if (c == charset[index])
			return (1);
		index++;
	}
	return (0);
}

void	ft_final_part(char **str_return, char *str, char *charset)
{
	int	aloc;
	int	count;

	aloc = 0;
	count = 0;
	while (*str != '\0')
	{
		if (ft_is_in_charset(*str, charset) == 0)
		{
			while (ft_is_in_charset(*str, charset) == 0 && *str != '\0')
			{
				str_return[aloc][count] = *str;
				count++;
				str++;
			}
			str_return[aloc][count] = 0;
			aloc++;
			count = 0;
		}
		str++;
	}
}

void	ft_scnd_size(char **str_return, char *str, char *charset)
{
	int	count;
	int	aloc;

	aloc = 0;
	count = 0;
	while (*str != '\0')
	{
		if (ft_is_in_charset(*str, charset) == 0)
		{
			while (ft_is_in_charset(*str, charset) == 0 && *str != '\0')
			{
				count++;
				str++;
			}
			str_return[aloc] = (char*)malloc(count * sizeof(char));
			aloc++;
			count = 0;
		}
		str++;
	}
}

int		ft_frst_size(char *str, char *charset)
{
	int	size;
	int	index;
	int	aux;

	aux = 0;
	index = 1;
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
	return (size + 1);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_return;
	int		first_size;

	first_size = ft_frst_size(str, charset);
	str_return = (char**)malloc(sizeof(char*) * first_size);
	ft_scnd_size(str_return, str, charset);
	ft_final_part(str_return, str, charset);
	str_return[first_size] = NULL;
	return (str_return);
}
