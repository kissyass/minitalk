/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:34:11 by ykissiko          #+#    #+#             */
/*   Updated: 2022/12/11 15:33:51 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_rec_bits(int signal, siginfo_t *info, void *other)
{
	static int	bit;
	static int	c;

	(void)other;
	if (signal == SIGUSR1)
		c |= (00000001 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	pid = getpid();
	if (argc == 1)
		ft_printf("The pid: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_rec_bits;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
