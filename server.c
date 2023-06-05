/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:45:41 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/05 15:30:10 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <unistd.h>
#include <signal.h>

void ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    char c = '0' + n % 10;
    write(1, &c, 1);
}

void handle_signal(int sig, siginfo_t *info, void *context)
{
    (void)info;
    (void)context;
    static int bits = 0;
    static char c = 0;

    if (sig == SIGUSR2)
    {
        c = c | (1 << bits);
    }
    bits = bits + 1;
    if (bits == 8)
    {
        write(1, &c, 1);
        bits = 0;
        c = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        write(2, "An error occurred\n", 18);
        return (1);
    }
    write(1, "PID: ", 5);
    ft_putnbr(getpid());
    write(1, "\n", 1);
    while (1)
        pause();
    return (0);
}



