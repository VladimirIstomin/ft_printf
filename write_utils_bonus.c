/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:12:19 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/19 14:33:22 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	write_num_without_sign(int n)
{
	char	num;
	int		wb;

	wb = 0;
	if (n / 10 != 0)
		wb += write_num_without_sign(n / 10);
	num = ft_abs(n % 10) + '0';
	wb += write(1, &num, 1);
	return (wb);
}

int	write_string(char *s, int len)
{
	int	wb;

	wb = 0;
	if (!s)
		wb += write(1, "(null)", 6);
	else
	{
		if (len < 0 || len > (int)ft_strlen(s))
			len = ft_strlen(s);
		wb += write(1, s, len);
	}
	return (wb);
}

int	write_ul_in_notation(unsigned long int n, char *notation_symbols)
{
	char	symbol;
	size_t	notation;
	int		wb;

	wb = 0;
	notation = ft_strlen(notation_symbols);
	if (n / notation != 0)
		wb += write_ul_in_notation(n / notation, notation_symbols);
	symbol = notation_symbols[n % notation];
	wb += write(1, &symbol, 1);
	return (wb);
}

int	write_char(char c)
{
	int		wb;

	wb = 0;
	wb += write(1, &c, 1);
	return (wb);
}

int	write_char_n_times(char c, int n)
{
	int	wb;

	wb = 0;
	while (n > 0)
	{
		wb += write(1, &c, 1);
		n--;
	}
	return (wb);
}
