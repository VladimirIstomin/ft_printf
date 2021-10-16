/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:26:34 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/15 14:57:21 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define ERROR -1
# define CONVERSIONS "cspdiuxX%%"
# define MODIFICATORS "-.# +0123456789"
# define POS_DIGITS "123456789"
# define AFTER_DIGIT "0123456789.cspdiuxX%%"

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_format
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
}				t_format;

int			ft_printf(const char *format_str, ...);
t_format	**free_params_format(t_format **params_format, size_t end);
t_format	*create_format(const char *fs, size_t *i);

#endif