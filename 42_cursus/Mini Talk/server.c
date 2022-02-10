/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:06:30 by lrosendo          #+#    #+#             */
/*   Updated: 2022/02/10 22:27:40 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_msg(int sig)
{
	static int bit_counter;
	static int answer;

	if (sig == SIGUSR2)
		answer |= 1<<bit_counter;
	bit_counter++;
	if (bit_counter == 8)
	{
		ft_putchar_fd(answer, 1);
		bit_counter = 0;
		answer = 0;
	}
}

void	exiting(int sig)
{
	ft_putstr_fd("Exit with success\n", 1);
	exit(1);
}

int main(int argc, char** argv)
{
	struct sigaction sa;
	struct sigaction exit;
	int pid;

	if (argc > 1 || argv[1])
		return(error(2));
	pid = getpid();//To get the server PID
	sa.sa_handler = &get_msg;//handling the signal func to recieve the msg
	exit.sa_handler = &exiting;//handling the signal func to exit
	ft_putstr_fd("My PID is: ", 1);
	ft_putstr_fd(ft_itoa(pid), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &exit, NULL);
	while (1)
		pause();
	return(0);
}
