/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:20 by lrosendo          #+#    #+#             */
/*   Updated: 2022/02/10 22:26:28 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	send_char(int pid, char c)//send the msg to the server by bits signals.
{
	int bit_counter;

	bit_counter = 0;
	while (bit_counter < 8)//Go only until 8, because one char have only 8 bits. 
	{
		if (c & (1 << bit_counter))
		{
			if(kill(pid, SIGUSR2) == -1)//Send a msg to the server to do -> c |= 1<< bit_counter...
				return (0);	//it means the variable will add the value 1<< bit_counter with the...
							//previously value, when it get on 8 bit_counters the total value will be the same as the char value
		}
		else
		{
			if(kill(pid, SIGUSR1) == -1)//Does nothing, only tell my server to put a +1 on it's bit_counter
				return(0);
		}
		bit_counter++;
		usleep(600);
	}
	return (1);
}

int main (int argc, char** argv)
{
	int pid;
	int aux;

	if (argc != 3)
		return(error(0));
	pid = ft_atoi(argv[1]);
	aux = 0;
	while (argv[2][aux])
	{
		if (!send_char(pid, argv[2][aux]))
		{
			error(1);
			return(0);
		}
		aux++;
	}
	return(0);
}