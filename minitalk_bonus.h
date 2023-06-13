/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:27:48 by tdelgran          #+#    #+#             */
/*   Updated: 2023/06/12 11:30:07 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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