/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:16:10 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/19 14:33:11 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	validate_format(const char *format_str, int *i)
{
	int		is_dot;
	char	curr;
	char	next;

	is_dot = 0;
	while (format_str[++(*i)])
	{
		curr = format_str[*i];
		next = format_str[*i + 1];
		if (ft_strchr(CONVERSIONS, curr))
			return (*i);
		else if (curr == '.' && !is_dot)
			is_dot = 1;
		else if
		(
			!ft_strchr(MODIFICATORS, curr)
			|| (is_dot && !ft_isdigit(curr))
			|| (ft_strchr(POS_DIGITS, curr) && !ft_strchr(AFTER_DIGIT, next))
		)
			return (ERROR);
	}
	return (ERROR);
}

static int	get_params_number(t_format	**formats, int n_formats)
{
	int	n_params;
	int	i;

	i = 0;
	n_params = 0;
	while (i < n_formats)
	{
		if (formats[i]->type != '%')
			n_params++;
		i++;
	}
	return (n_params);
}

static int	get_formats_number(const char *format_str)
{
	int	i;
	int	n_params;

	i = 0;
	n_params = 0;
	while (format_str[i])
	{
		if (format_str[i] == '%')
		{
			if (validate_format(format_str, &i) != ERROR)
				n_params++;
			else
				return (ERROR);
		}
		i++;
	}
	return (n_params);
}

static t_format	**parse_formats_from_format_string(const char *fs, int n_params)
{
	t_format	**formats;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	formats = malloc(sizeof(t_format) * (n_params));
	if (!formats)
		return (NULL);
	while (fs[i])
	{
		if (fs[i] == '%')
		{
			formats[j] = parse_format(fs, &i);
			if (!formats[j])
				return (free_parsed_formats(formats, j));
			j++;
		}
		i++;
	}
	return (formats);
}

int	ft_printf(const char *fs, ...)
{
	int			n_formats;
	int			n_params;
	t_format	**formats;
	va_list		ap;
	int			wb;

	n_formats = get_formats_number(fs);
	if (n_formats == ERROR)
		return (ERROR);
	formats = parse_formats_from_format_string(fs, n_formats);
	if (!formats)
		return (ERROR);
	va_start(ap, fs);
	n_params = get_params_number(formats, n_formats);
	wb = write_formatted_string(ap, fs, formats);
	free_parsed_formats(formats, n_formats);
	va_end(ap);
	return (wb);
}
