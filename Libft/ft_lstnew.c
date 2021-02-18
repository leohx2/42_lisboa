/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:12:47 by lrosendo          #+#    #+#             */
/*   Updated: 2021/02/18 19:13:58 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*to_return;

	if (!(to_return = (t_list *)malloc(sizeof(to_return))))
		return (NULL);
	to_return->content = content;
	to_return->next = 0;
	return (to_return);
}
