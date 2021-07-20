/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:33:15 by lrosendo          #+#    #+#             */
/*   Updated: 2021/07/20 12:33:35 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_todo(t_order *to_do)
{
	if (to_do->ra == 1 && to_do->rb == 1)
	{
		to_do->ra = 0;
		to_do->rb = 0;
		to_do->rr = 1;
	}
	if (to_do->sa == 1 && to_do->sb == 1)
	{
		to_do->sa = 0;
		to_do->sb = 0;
		to_do->ss = 1;
	}
	if (to_do->rra == 1 && to_do->rrb == 1)
	{
		to_do->rra = 0;
		to_do->rrb = 0;
		to_do->rrr = 1;
	}
}

int		*get_chunk(t_swap *numbers)// para encontrar o chunk que irá passar para o STACK B, até 20 números, e deixar no minimo 5 no stack A, lembrando que só irá passar para essa func caso o limit_a > 5.
{
	int	*chunk;
	int limit;
	int index;
	int hold_fst;
	int	hold_snd;

	limit = 1;
	hold_fst = numbers->numbers_a[get_biggest(numbers, 'a')];
	hold_snd = numbers->numbers_a[get_smallest(numbers, 'a')];// vai servir para guardar a posicao do menor numero para n ser confundido dps
	if (numbers->limit_a < MAX_CHUNK + 5)
		chunk = (int*)ft_calloc(sizeof(int), (numbers->limit_a - 5));
	else
		chunk = (int*)ft_calloc(sizeof(int), MAX_CHUNK);
	chunk[0] = hold_snd;
	while (limit < (numbers->limit_a - 5) && limit <  MAX_CHUNK)
	{
		index = 0;
		while (index < numbers->limit_a)
		{
			if (numbers->numbers_a[index] > hold_snd && numbers->numbers_a[index] < hold_fst)
				hold_fst = numbers->numbers_a[index];
			index++;
		}
		hold_snd = hold_fst;
		hold_fst = numbers->numbers_a[get_biggest(numbers, 'a')];
		chunk[limit] = hold_snd;
		limit++;
	}
	index = 0;
	numbers->limit_chunk = limit;
	return(chunk);	
}

int		get_posicion(int iten1, int total_arg)// to find out how many moves I really need
{
	if  (total_arg % 2 == 0)
	{
		if (iten1 <= total_arg/2 )			
			return(iten1);
		else if (iten1 > total_arg/2)
			return(total_arg - iten1);
	}
	else if (total_arg %  2 == 1)
	{
		if (iten1 <= total_arg/2 + 1)
			return(iten1);
		else if (iten1 > total_arg/2 + 1)
			return(total_arg - iten1);
	}
	return (1);
}

int		get_first_p(t_swap *numbers, int *chunk)
{
	int index;
	int index2;
	int	hold;

	index = 0;
	hold = -1;
	while (index < numbers->limit_a)
	{
		//printf("ESSE SAO OS OIS DA VERDADE!\n\n");
		index2 = 0;
		while (index2 < numbers->limit_chunk)
		{
			//printf("%d || %d || %d\n", numbers->numbers_a[index], chunk[index2], numbers->limit_chunk);
			if (numbers->numbers_a[index] == chunk[index2] && hold == -1)
				{
					hold = index;
				}
			else if (numbers->numbers_a[index] == chunk[index2])
			{
				if (get_posicion(index, numbers->limit_a) < get_posicion(hold, numbers->limit_a))
					hold = index;
				else if (get_posicion(index, numbers->limit_a) == get_posicion(hold, numbers->limit_a))
				{
					if (numbers->numbers_a[index] < numbers->numbers_a[hold])
						hold = index;
				}
			}
			index2++;
		}
		index++;
	}
	return (hold);
}

void	move_chunk(int *chunk, t_swap *numbers, t_order *to_do)
{
	int	index;
	int index2;

	index = get_first_p(numbers, chunk);
	up_or_down(index, numbers->limit_a, to_do);
}

void	up_or_down(int iten1, int total_arg, t_order *to_do)//TODO...
{
	if (iten1 == 0)
		to_do->pb = 1;
	else if  (total_arg % 2 == 0)
	{
		if (iten1 <= total_arg/2 )			
			to_do->ra = 1;
		else if (iten1 > total_arg/2)
			to_do->rra = 1;
	}
	else if (total_arg %  2 == 1)
	{
		if (iten1 <= total_arg/2 + 1)
			to_do->ra = 1;
		else if (iten1 > total_arg/2 + 1)
			to_do->rra = 1;
	}
}

int	check_b_order(t_swap *numbers, t_order *to_do)
{
	if (!numbers->b_used || numbers->limit_b < 2)
		return (1);
	return(1);
}
