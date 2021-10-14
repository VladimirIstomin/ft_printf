/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:16:10 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/13 17:41:12 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

// int	validate_format(const char *format_start)
// {
// 	int	i;

// 	i = 0;
// 	while (format_start[i] && !ft_strchr("cspdiuxX%%", format_start[i]))
// 	{
		
// 		i++;
// 	}
// 	if (!format_start[i])
// 		return (0);
// }

static size_t	get_params_number(const char *format_str)
{
	size_t	i;
	size_t	n_args;

	i = 0;
	n_args = 0;
	while (i < ft_strlen(format_str))
	{
		if (format_str[i] == '%' && format_str[i + 1] != '%')
			n_args++;
		i++;
	}
	return (n_args);
}

int	ft_printf(const char *format_str, ...)
{
	//va_list	argptr;
	size_t		n_args;

	n_args = get_params_number(format_str);
	return (0);
}

int	main(void)
{
	char	str[] = "hello %s %d%i world %%% %";

	ft_printf(str);

	printf("%-10.10d\n", 12);
	return (0);
}
