/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:54:36 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 16:35:08 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	write_additional(t_format *format, const void *value)
{
	int	wb;

	wb = 0;
	if (ft_strchr("di", format->type) && (int)value < 0)
		wb += write(1, "-", 1);
	else if (ft_strchr("diu", format->type) && format->is_space)
		wb += write(1, " ", 1);
	else if (ft_strchr("diu", format->type) && format->is_plus)
		wb += write(1, "+", 1);
	if (format->is_hash && format->type == 'x')
		wb += write(1, "0x", 2);
	else if (format->is_hash && format->type == 'X')
		wb += write(1, "0X", 2);
	return (wb);
}

int	write_content(t_format *format, const void *value)
{
	int	wb;

	wb = 0;
	if (format->type == 'c')
		wb += f_putchar((char)value);
	else if (format->type == 's')
		wb += put_string((char *)value);
	else if (ft_strchr("di", format->type))
		wb += put_num((int)value);
	else if (format->type == 'u')
		wb += put_unsigned_system((unsigned int)value, "0123456789");
	else if (format->type == 'x')
		wb += put_unsigned_system((unsigned int)value, "0123456789abcdef");
	else if (format->type == 'X')
		wb += put_unsigned_system((unsigned int)value, "0123456789ABCDEF");
	else if (format->type == '%')
		wb += write(1, "%%", 1);
	return (wb);
}
