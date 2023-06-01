/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:45:54 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/01 14:56:18 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_char(int server_pid, char c)
{
    int i = 7;
    while (i >= 0)
    {
        int bit = (c >> i) & 1;
        if (bit == 0)
        {
            if (kill(server_pid, SIGUSR1) == -1) 
            {
                write(2, "Error\n", 6);
                exit(1);
            }
        } 
        else 
        {
            if (kill(server_pid, SIGUSR2) == -1) 
            {
                write(2, "Error\n", 6);
                exit(1);
            }
        }
        usleep(500);
        i--;
    }
}

int main(int argc, char *argv[])
{
    int server_pid = atoi(argv[1]);
    char *str = argv[2];
    size_t i = 0;
    
    if (argc != 3) 
    {
        write(2, "Usage: ./client [server_pid] [string]\n", 39);
        return 1;
    }
    while (i < ft_strlen(str)) 
    {
        send_char(server_pid, str[i]);
        i++;
    }
    return 0;
}
