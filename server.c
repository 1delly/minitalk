/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:45:41 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/01 14:49:28 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void handler(int sig)
{
    int g_char;
    int g_bits;
    
    g_bits = 0;
    g_char = 0;
    g_char = g_char << 1;
    if (sig == SIGUSR2)
        g_char = g_char | 1;
    g_bits++;
    if (g_bits == 8)
        write(1, &g_char, 1);
}

int main()
{
    struct sigaction sa;

    sa.sa_handler = &handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1 ||
        sigaction(SIGUSR2, &sa, NULL) == -1) {
        write(2, "Error\n", 6);
        exit(1);
    }

    write(1, "PID: ", 5);
    ft_putnbr(getpid());
    write(1, "\n", 1);

    while (1) {
        pause();
    }
    return 0;
}

