/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:12:19 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 20:15:00 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	write_num_without_sign(int n)
{
	char	num;
	int		wb;

	wb = 0;
	if (n / 10 != 0)
		wb += put_num(n / 10);
	num = ft_abs(n % 10) + '0';
	wb += write(1, &num, 1);
	return (wb);
}

int	write_string(char *s)
{
	int	wb;

	wb = 0;
	wb += write(1, s, ft_strlen(s));
	return (wb);
}

int	write_unsigned_in_notation(unsigned int n, char *notation_symbols)
{
	char	symbol;
	size_t	notation;
	int		wb;

	wb = 0;
	notation = ft_strlen(notation_symbols);
	if (n / notation != 0)
		wb += write_unsigned_in_notation(n / notation, notation_symbols);
	symbol = notation_symbols[n % notation];
	wb += write(1, &symbol, 1);
	return (wb);
}

int	white_char(char c)
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
