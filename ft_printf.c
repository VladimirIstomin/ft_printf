/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:16:10 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 20:16:39 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	validate_param(const char *format_str, int *i)
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

static int	get_params_number(const char *format_str)
{
	int	i;
	int	n_params;

	i = 0;
	n_params = 0;
	while (format_str[i])
	{
		if (format_str[i] == '%')
		{
			if (validate_param(format_str, &i) != ERROR)
				n_params++;
			else
				return (ERROR);
		}
		i++;
	}
	return (n_params);
}

static t_format	**create_params_format(const char *fs, int n_params)
{
	t_format	**params_format;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	params_format = malloc(sizeof(t_format) * (n_params));
	if (!params_format)
		return (NULL);
	while (fs[i])
	{
		if (fs[i] == '%')
		{
			params_format[j] = create_format(fs, &i);
			if (!params_format[j])
				return (free_params_format(params_format, j));
			j++;
		}
		i++;
	}
	return (params_format);
}

int	ft_printf(const char *format_str, ...)
{
	int			n_params;
	t_format	**params_format;

	n_params = get_params_number(format_str);
	if (n_params == ERROR)
		return (-1);
	params_format = create_params_format(format_str, n_params);
	if (!params_format)
		return (0);
	printf("conversion type: %c\n", params_format[2]->type);
	printf("min width: %d\n", params_format[2]->min_width);
	printf("digit width: %d\n", params_format[2]->digit_width);
	printf("is dash: %d\n", params_format[2]->is_dash);
	printf("is dot: %d\n", params_format[2]->is_dot);
	printf("is hash: %d\n", params_format[2]->is_hash);
	printf("is plus: %d\n", params_format[2]->is_plus);
	printf("is space: %d\n", params_format[2]->is_space);
	printf("is zero: %d\n", params_format[2]->is_zero);
	return (n_params);
}

int	main(void)
{
	//char	*fs = "%.c %.c %0 0 00 1412c";
	//cspdiuxX%%

	//printf("N_PARAMS: %d\n", ft_printf(fs));
	printf("%14.012d %12%", 12);
	return (0);
}
