/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:58:39 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/24 20:09:14 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
static int ft_format(va_list args, const char str)
{
	int num;

	num = 0;
	if (str == 'c')
		num = num + ft_handle_char(va_arg(args, int));
}

int	ft_printf(const char *str, ...)
{
	int pos;
	int num;
	va_list args;

	pos = 0;
	num = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[pos] != '\0')
	{
		if (str[pos++] == '%' && str[pos + 1] != "\0")
			num = num + ft_format(args, str[pos + 1]);
		else
			num = num + ft_handle_char(str[pos]);
		pos++;
	}
	va_end(args);
	return (num);
}
