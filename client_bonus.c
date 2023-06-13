/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:25:37 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/13 11:47:20 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	pid_ok(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		usleep(100);
		usleep(100);
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		bit--;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		write(2, "Error: ./client [PID] [message]\n", 32);
		return (1);
	}
	if (!pid_ok(argv[1]))
	{
		write(2, "Invalid PID\n", 12);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	if (pid == -1)
		write(1, "Message not recieved\n", 22);
	else
		write(1, "Message recieved\n", 18);
	return (0);
}
