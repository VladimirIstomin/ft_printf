/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:12:19 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 16:34:50 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	put_num(int n)
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

int	put_string(char *s)
{
	int	wb;

	wb = 0;
	wb += write(1, s, ft_strlen(s));
	return (wb);
}

int	put_unsigned_system(unsigned int n, char *system)
{
	char	num;
	size_t	system_len;
	int		wb;

	wb = 0;
	system_len = ft_strlen(system);
	if (n / system_len != 0)
		wb += put_unsigned_system(n / system_len, system);
	num = system[n % system_len];
	wb += write(1, &num, 1);
	return (wb);
}

int	f_putchar(char c)
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