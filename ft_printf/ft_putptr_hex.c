/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:35:04 by egomez            #+#    #+#             */
/*   Updated: 2023/11/25 11:47:06 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_hex(unsigned long long ptr, int i)
{
	char	*base;

	base = "0123456789abcdef";
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (ptr / 16 != 0)
		i = ft_putptr_hex(ptr / 16, i);
	else
		write(1, "0x", 2);
	i += ft_printchar(base[ptr % 16]);
	return (i);
}
