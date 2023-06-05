/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:45:54 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/05 15:24:53 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <unistd.h>
#include <stdlib.h>

void send_bit(int pid, int bit)
{
    int signal;
    
    if (bit == 0)
        signal = SIGUSR1;
    else
        signal = SIGUSR2;
    if (kill(pid, signal) == -1)
    {
        write(2, "An error occurred\n", 18);
        exit(1);
    }
    usleep(100);
}

void send_char(int pid, char c)
{
    int bit = 0;
    while (bit < 8)
    {
        send_bit(pid, c & (1 << bit));
        bit++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        write(2, "Usage: ./client [PID] [message]\n", 31);
        return (1);
    }
    int pid = atoi(argv[1]);
    char *str = argv[2];
    while (*str)
    {
        send_char(pid, *str);
        str++;
    }
    return (0);
}
