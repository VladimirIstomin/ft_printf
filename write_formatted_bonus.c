/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_formatted_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:18:48 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/19 14:33:18 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	write_parameter_prefix(t_format *format, const void *val)
{
	int	wb;

	wb = 0;
	if (ft_strchr("di", format->type) && (int)val < 0)
		wb += write(1, "-", 1);
	else if (ft_strchr("diu", format->type) && format->is_space)
		wb += write(1, " ", 1);
	else if (ft_strchr("diu", format->type) && format->is_plus)
		wb += write(1, "+", 1);
	else if (format->type == 'p')
		wb += write(1, "0x", 2);
	else if (format->is_hash && format->type == 'x' && (unsigned)val != 0)
		wb += write(1, "0x", 2);
	else if (format->is_hash && format->type == 'X' && (unsigned)val != 0)
		wb += write(1, "0X", 2);
	return (wb);
}

static int	write_initial_parameter(t_format *format, const void *val)
{
	int	wb;

	wb = 0;
	if (format->type == 'c')
		wb += write_char((char)val);
	else if (format->type == 's' && !format->is_dot)
		wb += write_string((char *)val, -1);
	else if (format->type == 's' && format->is_dot)
		wb += write_string((char *)val, format->char_width);
	else if (format->type == 'p')
		wb += write_ul_in_notation((unsigned long)val, HEX_LOWER);
	else if (ft_strchr("di", format->type))
		wb += write_num_without_sign((int)val);
	else if (format->type == 'u')
		wb += write_ul_in_notation((unsigned)val, DECIMAL);
	else if (format->type == 'x')
		wb += write_ul_in_notation((unsigned)val, HEX_LOWER);
	else if (format->type == 'X')
		wb += write_ul_in_notation((unsigned)val, HEX_UPPER);
	else if (format->type == '%')
		wb += write(1, "%%", 1);
	return (wb);
}

static void	set_prefix_vars(t_format *format, const void *val, int *nz, int *ns)
{
	size_t	val_len;

	*nz = 0;
	*ns = 0;
	val_len = get_parameter_len(val, format->type);
	if (format->type == 'p')
		val_len += 2;
	if (ft_strchr("diuxX", format->type) && format->is_zero)
		*nz = format->min_width - val_len;
	else if (ft_strchr("diuxX", format->type) && format->is_dot)
		*nz = format->char_width - val_len;
	if (ft_strchr("di", format->type) && (int)val < 0 && format->is_dot)
		(*nz)++;
	if (*nz < 0)
		*nz = 0;
	*ns = format->min_width - val_len - *nz;
}

static int	write_formatted_parameter(t_format *format, const void *val)
{
	int		wb;
	int		n_zeros;
	int		n_spaces;

	wb = 0;
	set_prefix_vars(format, val, &n_zeros, &n_spaces);
	if (!format->is_dash)
		wb += write_char_n_times(' ', n_spaces);
	wb += write_parameter_prefix(format, val);
	wb += write_char_n_times('0', n_zeros);
	wb += write_initial_parameter(format, val);
	if (format->is_dash)
		wb += write_char_n_times(' ', n_spaces);
	return (wb);
}

int	write_formatted_string(va_list ap, const char *fs, t_format **formats)
{
	int	i;
	int	wb;
	int	j;

	wb = 0;
	i = 0;
	j = 0;
	while (fs[i])
	{
		if (fs[i] == '%')
		{
			i++;
			if (formats[j]->type == '%')
				wb += write_formatted_parameter(formats[j], NULL);
			else
				wb += write_formatted_parameter(formats[j], va_arg(ap, void *));
			while (!ft_strchr(CONVERSIONS, fs[i]))
				i++;
			j++;
		}
		else
			wb += write_char(fs[i]);
		i++;
	}
	return (wb);
}
