/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:37:52 by yudemir           #+#    #+#             */
/*   Updated: 2025/03/16 15:35:39 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putpid(pid_t n)
{
	char	c;

	if (n > 9)
	{
		ft_putpid((n / 10));
		ft_putpid((n % 10));
	}
	else
	{
		c = 48 + n;
		write(1, &c, 1);
	}
}

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static int	c = 0;

	(void)context;
	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = (c << 1) | 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "Error detected, restart program.", 33);
		return (1);
	}
	server_pid = getpid();
	write(1, "Server PID: ", 13);
	ft_putpid(server_pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
