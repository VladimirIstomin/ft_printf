/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:26:34 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/16 16:47:31 by gmerlene         ###   ########.fr       */
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
t_format	*create_empty_format_structure(void);
void		ease_format_flags(t_format *format);
t_format	**free_params_format(t_format **params_format, size_t end);
t_format	*create_format(const char *fs);
t_format	**create_params_format(const char *fs, int n_params);
int			write_char_n_times(char c, int n);
int			write_additional(t_format *format, const void *value);
int			write_content(t_format *format, const void *value);
int			put_string(char *s);
size_t		get_printed_len(const void *obj, char type);
int			put_unsigned_system(unsigned int n, char *system);
int			f_putchar(char c);
int			put_num(int n);

#endif