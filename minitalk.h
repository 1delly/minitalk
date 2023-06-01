/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:48:58 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/01 14:49:50 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "../Printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig);
int main();
void send_char(int server_pid, char c);
int main(int argc, char *argv[]);
void	ft_putnbr(int nb);
size_t	ft_strlen(const char *str);

#endif