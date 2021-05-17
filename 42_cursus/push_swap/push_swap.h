/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:10:37 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/17 11:59:37 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct push_swap
{
	int *numbers;
	int	argc;
	char **argv;
}	t_swap;


void	ft_putchar(char c);
int		ft_putstr(const char *s);
void	check_error(t_swap numbers);

#endif
