/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:12:54 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/13 20:31:32 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct	s_config
{
	char		conversion;
	char		*data;
	int			min_width;
	int			is_dash;
	int			is_dot;
	int			is_hash;
	int			is_plus;
	int			is_space;
	int			is_uppercase;
	int			is_zero;
}				t_config;
