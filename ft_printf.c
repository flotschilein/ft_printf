/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:58:39 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/25 20:06:13 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char str)
{
	int	num;

	num = 0;
	if (str == 'c')
		num = num + ft_handle_char(va_arg(args, int));
	else if (str == 's')
		num = num + ft_handle_str(va_arg(args, char *));
	else if (str == 'p')
		num = num + ft_handle_ptr(va_arg(args, void *));
	else if (str == 'd')
		num = num + ft_handle_nums(va_arg(args, int));
	else if (str == 'i')
		num = num + ft_handle_nums(va_arg(args, int));
	else if (str == 'u')
		num = num + ft_handle_unsigned(va_arg(args, unsigned int));
	else if (str == 'x')
		num = num + ft_convert_base16(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (str == 'X')
		num = num + ft_convert_base16(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (str == '%')
		num = num + ft_handle_char('%');
	return (num);
}

int	ft_printf(const char *str, ...)
{
	int		pos;
	int		num;
	int		res;
	va_list	args;

	pos = 0;
	num = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[pos] != '\0')
	{
		if (str[pos] == '%' && str[pos + 1] != '\0')
			res = ft_format(args, str[++pos]);
		else
			res = ft_handle_char(str[pos]);
		if(res == -1)
			return(-1);
		num = num + res;
		pos++;
	}
	va_end(args);
	return (num);
}
