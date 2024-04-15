/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:47:04 by egomez            #+#    #+#             */
/*   Updated: 2024/04/12 21:43:18 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "signal.h"

int	g_receive;

void	accept(int signal)
{
	(void)signal;
	g_receive = 1;
}

void	char_to_bin(char c, int pid)
{
	int	bits;
	int	convert;

	bits = 7;
	while (bits >= 0)
	{
		while (g_receive == 0)
			;
		g_receive = 0;
		convert = c >> bits;
		if (convert % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bits --;
	}
}

int	digit_pid(char *chain)
{
	int	i;

	i = 0;
	while (chain[i] && (chain[i] >= 0 && chain[i] <= 9))
		i ++;
	if (chain[i] == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*chain;

	if (ac != 3)
		return (1);
	if (ft_atoi(av[1]) < 1 || digit_pid(av[1]))
	{
		write(1, "Positive PID required\n", 25);
		return (1);
	}
	g_receive = 1;
	i = 0;
	pid = ft_atoi(av[1]);
	chain = av[2];
	signal(SIGUSR1, accept);
	while (chain[i] != 0)
	{
		char_to_bin(chain[i], pid);
		i++;
	}
	char_to_bin('\n', pid);
	return (0);
}
