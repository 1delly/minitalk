/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:48:58 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/05 15:31:49 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "../Printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void send_char(int pid, char c);
void send_bit(int pid, int bit);
void handle_signal(int sig, siginfo_t *info, void *context);

#endif