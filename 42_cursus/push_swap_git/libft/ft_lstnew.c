/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:12:47 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/12 20:16:23 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*to_return;

	to_return = (t_list *)malloc(sizeof(to_return));
	if (!(to_return))
		return (NULL);
	to_return->content = content;
	to_return->next = 0;
	return (to_return);
}
