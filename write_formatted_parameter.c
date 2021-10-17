/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_formatted_parameter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:18:48 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/17 18:17:26 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	set_prefix_vars(t_format *format, const void *val, int *nz, int *ns)
{
	size_t	val_len;
	
	val_len = get_parameter_len(val, format->type);
	*nz = format->digit_width - val_len;
	if (*nz < 0)
		*nz = 0;
	*ns = format->min_width - val_len - *nz;
}

int	write_formatted_parameter(t_format *format, const void *val)
{
	int		wb;
	int		n_zeros;
	int		n_spaces;

	wb = 0;
	set_prefix_vars(format, val, &n_zeros, &n_spaces);
	if (format->is_dash)
		wb += write_char_n_times(' ', n_spaces);
	wb += write_parameter_prefix(format, val);
	wb += write_char_n_times('0', n_zeros);
	wb += write_initial_parameter(format, val);
	if (!format->is_dash)
		wb += write_char_n_times(' ', n_spaces);
	return (wb);
}
