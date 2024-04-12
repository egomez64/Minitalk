/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:40:24 by egomez            #+#    #+#             */
/*   Updated: 2023/11/25 11:34:31 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nbr, char form, int i)
{
	char	*base;

	if (form == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr / 16 != 0)
		i = ft_putnbr_hex(nbr / 16, form, i);
	i += ft_printchar(base[nbr % 16]);
	return (i);
}
