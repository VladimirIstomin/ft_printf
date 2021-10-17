/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_formatted_parts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:54:36 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/17 19:20:27 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	write_parameter_prefix(t_format *format, const void *val)
{
	int	wb;

	wb = 0;
	if (ft_strchr("di", format->type) && *((int *)val) < 0)
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

int	write_initial_parameter(t_format *format, const void *val)
{
	int	wb;

	wb = 0;
	if (format->type == 'c')
		wb += write_char(*(char *)val);
	else if (format->type == 's')
		wb += write_string((char *)val);
	else if (ft_strchr("di", format->type))
		wb += write_num_without_sign(*(int *)val);
	else if (format->type == 'u')
		wb += write_unsigned_in_notation(*(unsigned *)val, "0123456789");
	else if (format->type == 'x')
		wb += write_unsigned_in_notation(*(unsigned *)val, "0123456789abcdef");
	else if (format->type == 'X')
		wb += write_unsigned_in_notation(*(unsigned *)val, "0123456789ABCDEF");
	else if (format->type == '%')
		wb += write(1, "%%", 1);
	return (wb);
}
