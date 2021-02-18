/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 23:51:10 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/17 23:51:10 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (lst || del || *lst)
	{
		while (lst && *lst)
		{
			aux = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = aux;
		}
	}
}