/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:25:27 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/13 20:32:31 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_config	*create_config(char *data)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
		return (NULL);
	config->conversion = 'c';
	config->data = data;
	config->min_width = 0;
	config->is_dash = 0;
	config->is_dot = 0;
	config->is_hash = 0;
	config->is_plus = 0;
	config->is_space = 0;
	config->is_uppercase = 0;
	config->is_zero = 0;
}
