/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:16:10 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/14 19:57:28 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static int	validate_param(const char *format_str)
{
	int	i;
	int	is_dot;

	i = 0;
	is_dot = 0;
	while (format_str[i])
	{
		if (ft_strchr(CONVERSIONS, format_str[i]))
			return (i);
		else if (!ft_strchr(MODIFICATORS, format_str[i]))
			return (ERROR);
		else if (format_str[i] == '.' && (is_dot
				|| !ft_strchr(ALLOWED, format_str[i + 1])))
			return (ERROR);
		else if (format_str[i] == '.' && !is_dot)
			is_dot = 1;
		else if (ft_strchr(POS_DIGITS, format_str[i]) 
			&& !ft_strchr(ALLOWED, format_str[i + 1]))
			return (ERROR);
		i++;
	}	
	return (0);
}

static int	get_params_number(const char *format_str)
{
	size_t	i;
	int		n_params;
	int		validation;

	i = 0;
	n_params = 0;
	while (format_str[i])
	{
		if (format_str[i] == '%')
		{
			validation = validate_param(format_str + i + 1);
			printf("%d\n", validation);
			if (validation != ERROR)
			{
				i += validation + 1;
				n_params++;
			}
			else
				return (ERROR);
		}
		i++;
	}
	return (n_params);
}

t_formating	**create_params_formating(const char *fs, int n_params)
{
	t_formating	**params_formating;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	params_formating = malloc(sizeof(t_formating) * (n_params));
	if (!params_formating)
		return (NULL);
	while (fs[i])
	{
		if (fs[i] == '%')
		{
			params_formating[j] = create_formating(fs + i + 1);
			if (!params_formating[j])
				return (free_params_formating(params_formating, j));
			j++;
		}
		i++; // need to shift i;
	}
	return (params_formating);
}

int	ft_printf(const char *format_str, ...)
{
	int			n_params;
	t_formating	**params_formating;

	n_params = get_params_number(format_str);
	if (n_params == ERROR)
		return (0);
	params_formating = create_params_formating(format_str, n_params);
	if (!params_formating)
		return (0);
	printf("conversion type: %c\n", params_formating[0]->conversion_type);
	printf("min width: %d\n", params_formating[0]->min_width);
	printf("digit width: %d\n", params_formating[0]->digit_width);
	printf("is dash: %d\n", params_formating[0]->is_dash);
	printf("is dot: %d\n", params_formating[0]->is_dot);
	printf("is hash: %d\n", params_formating[0]->is_hash);
	printf("is plus: %d\n", params_formating[0]->is_plus);
	printf("is space: %d\n", params_formating[0]->is_space);
	printf("is zero: %d\n", params_formating[0]->is_zero);
	return (n_params);
}

int	main(void)
{
	char	*fs = "%.234%";
	
	printf("N_PARAMS: %d\n", ft_printf(fs));
	return (0);
}
