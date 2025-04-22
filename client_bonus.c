/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:37:43 by yudemir           #+#    #+#             */
/*   Updated: 2025/03/16 15:36:24 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_rtr_signal = 0;

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_rtr_signal = 1;
	else
		exit(EXIT_SUCCESS);
}

void	ft_sendsignal(int pid, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			g_rtr_signal = 0;
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_rtr_signal == 0)
				pause();
			bit--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*str;

	if (ac != 3)
	{
		write(1, "Usage: ./client [server_pid] [message]\n", 39);
	}
	else
	{
		server_pid = ft_atoi(av[1]);
		if (kill(server_pid, 0) == -1 || server_pid < 0
			|| server_pid > 4194304)
		{
			write(1, "Invalid PID\n", 12);
			return (1);
		}
		str = av[2];
		signal(SIGUSR1, handler);
		ft_sendsignal(server_pid, str);
		ft_sendsignal(server_pid, "\n");
	}
}
