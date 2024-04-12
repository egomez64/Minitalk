/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converttreatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:30:47 by egomez            #+#    #+#             */
/*   Updated: 2023/11/25 13:45:15 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converttreatment(char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_printchar(va_arg(arg, unsigned int));
	if (c == 's')
		i = ft_putstr(va_arg(arg, char *));
	if (c == 'p')
		i = ft_putptr_hex(va_arg(arg, unsigned long long), 2);
	if (c == 'd' || c == 'i')
		i = ft_printnbr(va_arg(arg, int));
	if (c == 'u')
		i = ft_uputnbr(va_arg(arg, unsigned int));
	if (c == 'x')
		i = ft_putnbr_hex(va_arg(arg, unsigned int), 'x', 0);
	if (c == 'X')
		i = ft_putnbr_hex(va_arg(arg, unsigned int), 'X', 0);
	if (c == '%')
	{
		write(1, "%", 1);
		i = 1;
	}
	return (i);
}
