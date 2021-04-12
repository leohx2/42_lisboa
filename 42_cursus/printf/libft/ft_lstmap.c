/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:39:52 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 20:15:51 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list_return;

	list_return = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!(new))
		{
			while (list_return)
			{
				new = list_return->next;
				(*del)(list_return->content);
				free(list_return);
				list_return = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&list_return, new);
		lst = lst->next;
	}
	return (list_return);
}
