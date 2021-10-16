/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:14:28 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 16:28:15 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	get_num_len(int num)
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

size_t	get_unsigned_len_system(unsigned int num, int system_len)
{
	size_t	len;

	len = 1;
	while (num / system_len != 0)
	{
		num /= system_len;
		len++;
	}
	return (len);
}

size_t	get_printed_len(const void *obj, char type)
{
	if (type == 'c' || type == '%')
		return (1);
	else if (type == 's')
		return (ft_strlen((char *)obj));
	else if (ft_strchr("di", type))
		return (get_num_len((int)obj));
	else if (type == 'u')
		return (get_unsigned_len_system((unsigned char)obj, 10));
	else if (type == 'x' || type == 'X')
		return (get_unsigned_len_system((unsigned char)obj, 16));
	return (0);
}
