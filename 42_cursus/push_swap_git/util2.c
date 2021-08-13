/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:33:15 by lrosendo          #+#    #+#             */
/*   Updated: 2021/08/13 15:02:38 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_todo(t_order *to_do, t_swap *numbers)
{
	if (to_do->pa == 1)
	{
		if (up_or_down_b(get_biggest(numbers, 'b')
				, numbers->limit_b, to_do, numbers))
			to_do->pa = 0;
	}
	if (to_do->ra == 1 && to_do->rb == 1)
	{
		normalize(to_do, 'A');
		to_do->rr = 1;
	}
	else if (to_do->sa == 1 && to_do->sb == 1)
	{
		normalize(to_do, 'A');
		to_do->ss = 1;
	}
	else if (to_do->rra == 1 && to_do->rrb == 1)
	{
		normalize(to_do, 'A');
		to_do->rrr = 1;
	}
	else
		return (0);
	return (1);
}

int	*get_chunk(t_swap *numbers)
{
	int	*chunk;
	int	index;
	int	hold_fst;
	int	hold_snd;

	hold_fst = numbers->numbers_a[get_biggest(numbers, 'a')];
	hold_snd = numbers->numbers_a[get_smallest(numbers, 'a')];
	if (numbers->limit_a < MAX_CHUNK + 3)
		chunk = (int *)ft_calloc(sizeof(int), (numbers->limit_a - 3));
	else
		chunk = (int *)ft_calloc(sizeof(int), MAX_CHUNK);
	chunk[0] = hold_snd;
	chunk_maker_aux(numbers, &hold_snd, &hold_fst, chunk);
	return (chunk);
}

int	get_posicion(int iten1, int total_arg)
{
	if (total_arg % 2 == 0)
	{
		if (iten1 <= total_arg / 2)
			return (iten1);
		else if (iten1 > total_arg / 2)
			return (total_arg - iten1);
	}
	else if (total_arg % 2 == 1)
	{
		if (iten1 <= total_arg / 2 + 1)
			return (iten1);
		else if (iten1 > total_arg / 2 + 1)
			return (total_arg - iten1);
	}
	return (1);
}

static void	aux_get_posic(t_swap *numbers, int *chunk, t_aux *aux)
{
	if (numbers->numbers_a[aux->index] == chunk[aux->index2] && aux->hold == -1)
		aux->hold = aux->index;
	else if (numbers->numbers_a[aux->index] == chunk[aux->index2])
	{
		if (get_posicion(aux->index, numbers->limit_a)
			< get_posicion(aux->hold, numbers->limit_a))
			aux->hold = aux->index;
		else if (get_posicion(aux->index, numbers->limit_a)
			== get_posicion(aux->hold, numbers->limit_a))
		{
			if (numbers->numbers_a[aux->index] < numbers->numbers_a[aux->hold])
				aux->hold = aux->index;
		}
	}
	aux->index2++;
}

int	get_first_p(t_swap *numbers, int *chunk)
{
	t_aux	aux;

	aux.index = 0;
	aux.hold = -1;
	while (aux.index < numbers->limit_a)
	{
		aux.index2 = 0;
		while (aux.index2 < numbers->limit_chunk)
			aux_get_posic(numbers, chunk, &aux);
		aux.index++;
	}
	return (aux.hold);
}
