/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:33:17 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/25 13:51:18 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_a(t_swap *numbers, int size, t_order *to_do)
{
	printf("SIZE -> %d\tBIGGER %d\tSND_BIGGER %d \tSMALLER %d\tSND_SMALLER %d\n",
	size, numbers->biggest_a, numbers->snd_biggest_a, numbers->smallest_a, numbers->snd_smallest_a);
	//---------CONFIG SA---------//
	if (size == 2)
		to_do->sa = 1;
	else if (numbers->smallest_a == 1 && numbers->snd_smallest_a != 0)
	{
		if (numbers->smallest_a == 1 && numbers->snd_smallest_a != 2)
			to_do->sa = 1;
		else if (size == 3)
			to_do->sa = 1;
	}
	else if (numbers->smallest_a == 0 && numbers->biggest_a == 1
		&& numbers->snd_smallest_a == 2)
		to_do->sa = 1;
	else if (numbers->biggest_a == 0 && numbers->snd_biggest_a == 1)
		to_do->sa = 1;
	else if (numbers->smallest_a == 1 && numbers->snd_smallest_a == 0)
		to_do->sa = 1;
	//--------CONFIG RA--------//
	if (numbers->smallest_a != 0 && ((size % 2 == 1) && numbers->smallest_a < size/2 + 1
		|| (size % 2 == 0) && numbers->smallest_a < size/2) && to_do->sa == 0)
		to_do->ra = 1;
	//------CONFIG RRA--------//
	else if (numbers->smallest_a != 1 && ((size % 2 == 1) && numbers->smallest_a >= size/2 + 1
		|| (size % 2 == 0) && numbers->smallest_a >= size/2) && to_do->sa == 0)
		to_do->rra = 1;
	//------CONFIG PB--------//
	else if (numbers->smallest_a == 0 && to_do->sa == 0
		|| (numbers->smallest_a == 1 && numbers->snd_smallest_a == 0) && to_do->sa == 0)
		to_do->pb = 1;
	return (0);
}
