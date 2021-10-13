/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:13:41 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/13 20:32:37 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_flags(t_config *config)
{
	if (config->is_plus)
		config->is_space = NULL;
	if (config->is_dash || config->min_width)
		config->is_zero = NULL;
}
