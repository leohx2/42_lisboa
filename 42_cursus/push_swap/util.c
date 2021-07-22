/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:33:17 by lrosendo          #+#    #+#             */
/*   Updated: 2021/07/22 09:07:02 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ss(t_swap *number, int stack)
{
	int	hold;

	if (stack == 'a')
	{
		hold = number->numbers_a[1];
		number->numbers_a[1] = number->numbers_a[0];
		number->numbers_a[0] = hold;
	}
	else if (stack == 'b')
	{
		hold = number->numbers_b[1];
		number->numbers_b[1] = number->numbers_b[0];
		number->numbers_b[0] = hold;
	}
}

void	exec_rr(t_swap *number, int stack, int limite)
{
	int	hold[limite];
	int i;

	i = 1;
	if (stack == 'a')
	{
		hold[limite - 1] = number->numbers_a[0];
		while (i < limite)
		{
			hold[i - 1] = number->numbers_a[i];
			i++;
		}
		i = 0;
		while (i < limite)
		{
			number->numbers_a[i] = hold[i];
			i++;
		}
	}
	else
	{
		hold[number->limit_b - 1] = number->numbers_b[0];
		while (i < limite)
		{
			hold[i - 1] = number->numbers_b[i];
			i++;
		}
		i = 0;
		while (i < limite)
		{
			number->numbers_b[i] = hold[i];
			i++;
		}
	}
}

void	exec_rrr(t_swap *number, int stack, int limite)
{
	int	hold[limite];
	int i;

	i = 1;
	if (stack == 'a')
	{
		hold[0] = number->numbers_a[limite - 1];
		while (i < limite)
		{
			hold[i] = number->numbers_a[i - 1];
			i++;
		}
		i = 0;
		while (i < limite)
		{
			number->numbers_a[i] = hold[i];
			i++;
		}
	}
	else if (stack == 'b' && number->b_used)
	{
		hold[0] = number->numbers_b[limite - 1];
		while (i < limite)
		{
			hold[i] = number->numbers_b[i - 1];
			i++;
		}
		i = 0;
		while (i < limite)
		{
			number->numbers_b[i] = hold[i];
			i++;
		}
	}
}

void	exec_pp(t_swap *number, int stack)
{
	if (stack == 'a')
	{
		exec_rr(number, 'a', number->limit_a);
		number->numbers_b[number->limit_b] = number->numbers_a[number->limit_a - 1];//usar o exec_rrb dps;
		number->limit_b += 1;
		number->b_used = 1;
		exec_rrr(number, 'b', number->limit_b);
		number->numbers_a[number->limit_a] = 0;
		number->limit_a -= 1;
	}
	else
	{
		exec_rr(number, 'b', number->limit_b);
		number->numbers_a[number->limit_a] = number->numbers_b[number->limit_b - 1];//usar o exec_rrb dps;
		number->limit_a += 1;
		exec_rrr(number, 'a', number->limit_a);
		number->numbers_b[number->limit_b] = 0;
		number->limit_b -= 1;
		if (number->limit_b <= 0)
			number->b_used = 0;
	}
}

int		pp_case1(t_swap *number, int stack)
{
	int	i;

	i = 2;
	if(stack == 'a')
	{
		if (number->limit_a == 3)
			return (0);
		while (i < number->limit_a)
		{
			if (number->numbers_a[i - 1] > number->numbers_a[i])
				return (1);//não esta organizado 
			i++;
		}
	}
	else
	{
		if (number->limit_b == 3)
			return (0);
		while (i < number->limit_b)
		{
			if (number->numbers_b[i - 1] < number->numbers_b[i])
				return (1);//não esta organizado 
			i++;
		}
	}
	return (0);
}

void	more_than_three(t_swap *numbers, t_order *to_do)
{
	int	*chunk;

	while (numbers->limit_a > 3)
	{
		chunk = get_chunk(numbers); // falta ainda configurar para quando houver casos de mais de 1 chunk.
		normalize(to_do);
		printa_dpsTira(numbers);
		move_chunk(chunk, numbers, to_do);
		ft_print_todo(numbers, *to_do);
		free(chunk);
	}
	three_or_less(numbers, to_do); //para utilizar esta funcao devo primeiro arrumar um check_order para o stack B
}

void	three_or_less(t_swap *numbers, t_order *to_do)
{
	int safe;

	safe = 0;
	while (check_order(numbers) && safe < 30)//dps colocar a ordem do stack B tbm!
	{
		
		printa_dpsTira(numbers);
		normalize(to_do);
		check_size_stack(numbers, to_do);
		check_todo(to_do);// -> função para verificar se há dois comandos iguais nos stacks.
		ft_print_todo(numbers, *to_do);
	}
}
