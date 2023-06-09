/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:45:54 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/12 11:26:36 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	return (0);
}
