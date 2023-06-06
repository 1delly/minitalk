/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:45:41 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/06 17:15:52 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_bits = 0;
char g_c = 0;
    
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

    if (sig == SIGUSR2)
        g_c = g_c | (1 << (7 - g_bits));
    g_bits = g_bits + 1;
    if (g_bits == 8)
    {
        write(1, &g_c, 1);
        g_bits = 0;
        g_c = 0;
    }
}

int main(void)
{
    struct sigaction    sa;

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
