/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:48:38 by egomez            #+#    #+#             */
/*   Updated: 2024/04/12 16:50:18 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "signal.h"

void	bin_to_char(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				i;
	(void)context;

	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	i++;
	kill(info->si_pid, SIGUSR1);
	if (i == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sign;

	sign.sa_sigaction = &bin_to_char;
	sign.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sign, NULL);
	sigaction(SIGUSR2, &sign, NULL);
	while (1)
		pause();
	return (0);
}
