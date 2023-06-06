/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:45:54 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/06 17:01:53 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_bit(int pid, int bit)
{
    int signal;
    
    if (bit == 0)
        signal = SIGUSR1;
    else
        signal = SIGUSR2;
    if (kill(pid, signal) == -1)
        write(2, "An error occurred\n", 18);
    usleep(1000);
}

void send_char(int pid, char c)
{
    int bit;
    int signal;

    bit = 7;
    while (bit >= 0)
    {
        if ((c & (1 << bit)) == 0)
            signal = SIGUSR1;
        else
            signal = SIGUSR2;
        if (kill(pid, signal) == -1)
            write(2, "An error occurred\n", 18);
        usleep(500);
        bit--;
    }
}


int main(int argc, char *argv[])
{
    int pid;
    char *str;
    
    if (argc != 3)
    {
        write(2, "Usage: ./client [PID] [message]\n", 31);
        return (1);
    }
    pid = atoi(argv[1]);
    str = argv[2];
    while (*str)
    {
        send_char(pid, *str);
        str++;
    }
    return (0);
}
