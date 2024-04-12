/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:09:00 by egomez            #+#    #+#             */
/*   Updated: 2023/11/25 11:43:11 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *arg0, ...);
int	ft_converttreatment(char c, va_list arg);
int	ft_putstr(char *str);
int	ft_printchar(char c);
int	ft_printnbr(int nb);
int	ft_putnbr_hex(unsigned int nbr, char form, int i);
int	ft_putptr_hex(unsigned long long ptr, int i);
int	ft_uputnbr(unsigned int nb);

#endif
