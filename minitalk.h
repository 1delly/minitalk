/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:48:58 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/12 11:18:55 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	send_char(int pid, char c);
void	handle_signal(int sig, siginfo_t *info, void *context);
int		ft_atoi(const char *str);
void	ft_putnbr(int nb);
int		ft_isdigit(int c);

#endif