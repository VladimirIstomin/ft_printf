/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:25:27 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 15:09:44 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format	*create_empty_format_structure(void)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (!format)
		return (NULL);
	format->type = 0;
	format->digit_width = 0;
	format->min_width = 0;
	format->is_dash = 0;
	format->is_dot = 0;
	format->is_hash = 0;
	format->is_plus = 0;
	format->is_space = 0;
	format->is_zero = 0;
	return (format);
}

void	ease_format_flags(t_format *format)
{
	if (format->is_plus)
		format->is_space = 0;
	if (format->is_dash || format->is_dot)
		format->is_zero = 0;
	if (ft_strchr("csp%%", format->type))
		format->digit_width = 0;
}

t_format	**free_params_format(t_format **params_format, size_t end)
{
	size_t	i;

	i = 0;
	while (i < end)
	{
		free(params_format[i]);
		i++;
	}
	free(params_format);
	params_format = NULL;
	return (NULL);
}

size_t	get_index_after_digits(const char *fs, size_t start)
{
	while (ft_isdigit(fs[start]))
		start++;
	return (--start);
}

t_format	*create_format(const char *fs)
{
	t_format	*format;
	size_t		i;

	format = create_empty_format_structure();
	if (!format)
		return (NULL);
	i = 0;
	while (ft_strchr(MODIFICATORS, fs[i]))
	{
		if (fs[i] == '-')
			format->is_dash = 1;
		else if (fs[i] == '.')
		{
			format->is_dot = 1;
			format->min_width = ft_atoi(fs + i + 1);
			i = get_index_after_digits(fs, i + 1);
		}
		else if (ft_strchr(POS_DIGITS, fs[i]))
		{
			format->digit_width = ft_atoi(fs + i);
			i = get_index_after_digits(fs, i);
		}
		else if (fs[i] == '#')
			format->is_hash = 1;
		else if (fs[i] == '+')
			format->is_plus = 1;
		else if (fs[i] == ' ')
			format->is_space = 1;
		else if (fs[i] == '0')
			format->is_zero = 1;
		i++;
	}
	if (!ft_strchr(CONVERSIONS, fs[i]))
		return (NULL);
	format->type = fs[i];
	ease_format_flags(format);
	return (format);
}
