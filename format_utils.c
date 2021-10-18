/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:25:27 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 15:09:44 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format	*create_empty_format_structure(void)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (!format)
		return (NULL);
	format->type = 0;
	format->char_width = 0;
	format->min_width = 0;
	format->is_dash = 0;
	format->is_dot = 0;
	format->is_hash = 0;
	format->is_plus = 0;
	format->is_space = 0;
	format->is_zero = 0;
	return (format);
}

static size_t	get_index_after_digits(const char *fs, size_t start)
{
	while (ft_isdigit(fs[start]))
		start++;
	return (--start);
}

static void	update_modificator(const char *fs, t_format *format, size_t *i)
{
	if (fs[*i] == '-')
		format->is_dash = 1;
	else if (fs[*i] == '.')
	{
		format->is_dot = 1;
		format->char_width = ft_atoi(fs + *i + 1);
		*i = get_index_after_digits(fs, *i + 1);
	}
	else if (ft_strchr(POS_DIGITS, fs[*i]))
	{
		format->min_width = ft_atoi(fs + *i);
		*i = get_index_after_digits(fs, *i);
	}
	else if (fs[*i] == '#')
		format->is_hash = 1;
	else if (fs[*i] == '+')
		format->is_plus = 1;
	else if (fs[*i] == ' ')
		format->is_space = 1;
	else if (fs[*i] == '0')
		format->is_zero = 1;
}

t_format	**free_parsed_formats(t_format **params_format, size_t end)
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

t_format	*parse_format(const char *fs, size_t *i)
{
	t_format	*format;

	format = create_empty_format_structure();
	if (!format)
		return (NULL);
	while (ft_strchr(MODIFICATORS, fs[++(*i)]))
		update_modificator(fs, format, i);
	if (!ft_strchr(CONVERSIONS, fs[*i]))
		return (NULL);
	format->type = fs[*i];
	if (format->is_plus)
		format->is_space = 0;
	if (format->is_dash || format->is_dot)
		format->is_zero = 0;
	return (format);
}
