/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:25:27 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/14 19:57:29 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

t_formating	*create_empty_formating_structure(void)
{
	t_formating	*formating;

	formating = malloc(sizeof(t_formating));
	if (!formating)
		return (NULL);
	formating->conversion_type = 0;
	formating->digit_width = 0;
	formating->min_width = 0;
	formating->is_dash = 0;
	formating->is_dot = 0;
	formating->is_hash = 0;
	formating->is_plus = 0;
	formating->is_space = 0;
	formating->is_zero = 0;
	return (formating);
}

void	ease_formating_flags(t_formating *formating)
{
	if (formating->is_plus)
		formating->is_space = 0;
	if (formating->is_dash || formating->is_dot)
		formating->is_zero = 0;
}

t_formating	**free_params_formating(t_formating **params_formating, size_t end)
{
	size_t	i;

	i = 0;
	while (i < end)
	{
		free(params_formating[i]);
		i++;
	}
	free(params_formating);
	params_formating = NULL;
	return (NULL);
}

size_t	get_index_after_digits(const char *fs, size_t start)
{
	while (ft_isdigit(fs[start]))
		start++;
	return (--start);
}

t_formating	*create_formating(const char *fs)
{
	t_formating	*formating;
	size_t		i;

	formating = create_empty_formating_structure();
	if (!formating)
		return (NULL);
	i = 0;
	while (ft_strchr(MODIFICATORS, fs[i]))
	{
		if (fs[i] == '-')
			formating->is_dash = 1;
		else if (fs[i] == '.')
		{
			formating->is_dot = 1;
			formating->min_width = ft_atoi(fs + i + 1);
			i = get_index_after_digits(fs, i + 1);
		}
		else if (ft_strchr(POS_DIGITS, fs[i]))
		{
			formating->digit_width = ft_atoi(fs + i);
			i = get_index_after_digits(fs, i);
		}
		else if (fs[i] == '#')
			formating->is_hash = 1;
		else if (fs[i] == '+')
			formating->is_plus = 1;
		else if (fs[i] == ' ')
			formating->is_space = 1;
		else if (fs[i] == '0')
			formating->is_zero = 1;
		i++;
	}
	if (!ft_strchr(CONVERSIONS, fs[i]))
		return (NULL);
	formating->conversion_type = fs[i];
	ease_formating_flags(formating);
	return (formating);
}
