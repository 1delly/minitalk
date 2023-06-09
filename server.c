/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:45:41 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/09 14:31:29 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static int bits = 0;
    static char c = 0;

    (void)info;
    (void)context;
    if (sig == SIGUSR1)
    {
        bits++;
    }
    else if (sig == SIGUSR2)
    {
        c |= (1 << bits);
        bits++;
    }
    if (bits == 8)
    {
        write(1, &c, 1);
        bits = 0;
        c = 0;
    }
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 \
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
