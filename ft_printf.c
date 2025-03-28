/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:58:39 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/28 15:56:12 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char str)
{
	if (str == 'c')
		return (ft_handle_char(va_arg(args, int)));
	else if (str == 's')
		return (ft_handle_str(va_arg(args, char *)));
	else if (str == 'p')
		return (ft_handle_ptr(va_arg(args, void *)));
	else if (str == 'd' || str == 'i')
		return (ft_handle_nums(va_arg(args, int)));
	else if (str == 'u')
		return (ft_handle_unsigned(va_arg(args, unsigned int)));
	else if (str == 'x')
		return (ft_convert_base16(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (str == 'X')
		return (ft_convert_base16(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (str == '%')
		return (ft_handle_char('%'));
	return (0);
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
		if (res == -1)
			return (-1);
		num = num + res;
		pos++;
	}
	va_end(args);
	return (num);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	ftprintfres;

// 	// int printfres;
// 	// printfres = printf("%x", "hello world");
// 	// printf("%i\n", printfres);
// }
