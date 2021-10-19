/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:26:34 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/19 13:56:13 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR -1
# define CONVERSIONS "cspdiuxX%%"
# define MODIFICATORS "-.# +0123456789"
# define POS_DIGITS "123456789"
# define AFTER_DIGIT "0123456789.cspdiuxX%%"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_format
{
	char		type;
	int			min_width;
	int			char_width;
	int			is_dash;
	int			is_dot;
	int			is_hash;
	int			is_plus;
	int			is_space;
	int			is_zero;
}				t_format;

int			ft_printf(const char *fs, ...);
t_format	**free_parsed_formats(t_format **params_format, size_t end);
t_format	*parse_format(const char *fs, size_t *i);
int			write_formatted_string(va_list ap, const char *fs, t_format **f);
size_t		get_parameter_len(const void *obj, char type);
int			write_num_without_sign(int n);
int			write_string(char *s, int len);
int			write_ul_in_notation(unsigned long int n, char *notation_symbols);
int			write_char(char c);
int			write_char_n_times(char c, int n);

#endif
