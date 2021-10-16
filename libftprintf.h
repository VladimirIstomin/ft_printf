/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:26:34 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 20:15:19 by gmerlene         ###   ########.fr       */
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
# include <unistd.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct s_format
{
	char		type;
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
t_format	*create_empty_format_structure(void);

size_t		get_parameter_len(const void *obj, char type);
int			write_formatted_parameted(t_format *format, const void *val);
int			write_parameter_prefix(t_format *format, const void *val);
int			write_initial_parameter(t_format *format, const void *val);
int			write_num_without_sign(int n);
int			write_string(char *s);
int			write_unsigned_in_notation(unsigned int n, char *notation_symbols);
int			white_char(char c);
int			write_char_n_times(char c, int n);

#endif