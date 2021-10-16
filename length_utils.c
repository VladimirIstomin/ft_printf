/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:14:28 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 20:03:27 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	get_num_len_without_sign(int num)
{
	size_t	len;

	len = 1;
	while (num / 10 != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static size_t	get_unsigned_len_in_notation(unsigned int num, int notation)
{
	size_t	len;

	len = 1;
	while (num / notation != 0)
	{
		num /= notation;
		len++;
	}
	return (len);
}

size_t	get_parameter_len(const void *obj, char type)
{
	if (type == 'c' || type == '%')
		return (1);
	else if (type == 's')
		return (ft_strlen((char *)obj));
	else if (ft_strchr("di", type))
		return (get_num_len_without_sign((int)obj));
	else if (type == 'u')
		return (get_unsigned_len_in_notation((unsigned char)obj, 10));
	else if (type == 'x' || type == 'X')
		return (get_unsigned_len_in_notation((unsigned char)obj, 16));
	return (0);
}
