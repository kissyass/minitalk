/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:43:13 by ykissiko          #+#    #+#             */
/*   Updated: 2022/12/11 15:36:05 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_rec_bits(int signal)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
		c |= (0000001 << bit);
	bit++;
	if (bit == 7)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	pid = getpid();
	if (argc == 1)
		ft_printf("The pid: %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_rec_bits);
		signal(SIGUSR2, ft_rec_bits);
		pause ();
	}
	return (0);
}
