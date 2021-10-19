/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:14:28 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/19 14:33:14 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	get_num_len(int num)
{
	size_t	len;

	len = 1;
	if (num < 0)
		len++;
	while (num / 10 != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static size_t	get_ul_len_in_notation(unsigned long int num, int notation)
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
	else if (type == 's' && (char *)obj != NULL)
		return (ft_strlen((char *)obj));
	else if (ft_strchr("di", type))
		return (get_num_len((int)obj));
	else if (type == 'u')
		return (get_ul_len_in_notation((unsigned int)obj, 10));
	else if (type == 'x' || type == 'X')
		return (get_ul_len_in_notation((unsigned int)obj, 16));
	else if (type == 'p')
		return (get_ul_len_in_notation((unsigned long int)obj, 16));
	return (0);
}
