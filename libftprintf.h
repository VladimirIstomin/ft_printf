/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:26:34 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/14 19:56:17 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define ERROR -1
# define ALLOWED "0123456789.cspdiuxX%%"
# define MODIFICATORS "-.# +0123456789"
# define CONVERSIONS "cspdiuxX%%"
# define POS_DIGITS "123456789"

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_formating
{
	char		conversion_type;
	int			min_width;
	int			digit_width;
	int			is_dash;
	int			is_dot;
	int			is_hash;
	int			is_plus;
	int			is_space;
	int			is_zero;
}				t_formating;

int			ft_printf(const char *format_str, ...);
t_formating	*create_empty_formating_structure(void);
void		ease_formating_flags(t_formating *formating);
t_formating	**free_params_formating(t_formating **params_formating, size_t end);
t_formating	*create_formating(const char *fs);
t_formating	**create_params_formating(const char *fs, int n_params);

#endif