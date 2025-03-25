/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:58:39 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/25 15:39:15 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int ft_format(va_list args, const char str)
{
	int num;

	num = 0;
	if (str == 'c')
		num = num + ft_handle_char(va_arg(args, int));
	if (str == 's')
		num = num + ft_handle_str(va_arg(args, char *));
	if (str == 'p')
		num = num + ft_handle_ptr(va_arg(args, void *));
	if (str == 'd')
		num = num + ft_handle_nums(va_arg(args, long int));
	if (str == 'i')
		num = num + ft_handle_nums(va_arg(args, long int));
	if (str == 'u')
		num = num + ft_handle_nums(va_arg(args, long int));
	if (str == 'x')
		num = num + ft_convert_base16(va_arg(args, size_t), "0123456789abcdef");
	if (str == 'X')
		num = num + ft_convert_base16(va_arg(args, size_t), "0123456789ABCDEF");
	if (str == '%')
		num = num + ft_handle_char('%');
	return (num);
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
		if (str[pos] == '%' && str[pos + 1] != '\0')
		{
			pos++;
			num = num + ft_format(args, str[pos + 1]);
		}
		else
			num = num + ft_handle_char(str[pos]);
		pos++;
	}
	va_end(args);
	return (num);
}
