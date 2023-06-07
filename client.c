/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:45:54 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/07 16:33:31 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid_ok(const char* str)
{
    while(*str)
    {
        if(!ft_isdigit(*str))
            return(0);
        str++;
    }
    return(1);
}

void	send_char(int pid, char c)
{
	int	bit;
	int	signal;

	bit = 7;
	while (bit >= 0)
	{
		if ((c & (1 << bit)) == 0)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
			write(2, "Error\n", 6);
		usleep(999);
		bit--;
	}
	if (kill(pid, SIGUSR2) == -1)
		write(2, "Error\n", 6);
	usleep(999);
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
