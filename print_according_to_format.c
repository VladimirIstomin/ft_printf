/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_according_to_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:18:48 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 16:43:08 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	print_param(t_format *format, const void *value)
{
	int		wb;
	size_t	value_len;
	int		n_zeros;
	int		n_spaces;

	wb = 0;
	wb += write_additional(format, value);
	value_len = get_printed_len(value, format->type);
	n_zeros = format->digit_width - value_len;
	if (n_zeros < 0)
		n_zeros = 0;
	n_spaces = format->min_width - value_len - n_zeros;
	if (format->is_dash)
		wb += write_char_n_times(' ', n_spaces);
	wb += write_char_n_times('0', n_zeros);
	wb += write_content(format, value);
	if (!format->is_dash)
		wb += write_char_n_times(' ', n_spaces);
	return (wb);
}

int	ftt_printf(char *fs, t_format *format, int size, ...)
{
	va_list	ap;
	int		i;
	int		wb;
	//char	*arg;

	(void)fs;
	i = 0;
	wb = 0;
	va_start(ap, size);
	while (i < size)
	{
		wb += print_param(format, va_arg(ap, void *));
		i++;
	}
	va_end(ap);
	return (wb);
}

int	main(void)
{
	// t_format	*format;
	// char		*fs = "%d";
	// int			val1 = 12;
	// char		val2 = 'z';
	// char		*ptr;

	// format = create_empty_format_structure();
	// format->conversion_type = 'd';
	// format->is_space = 0;
	// format->is_plus = 1;
	// ftt_printf(fs, format, 1, val1);
	// printf("\n");
	// //printf("%s\n", ptr);
	// printf("%zu\n", ft_strlen((void *)ptr));
	printf("%12.3d\n", 'a');
	return (0);
}
