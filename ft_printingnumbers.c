/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printingnumbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:34:40 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/25 18:15:12 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_handle_unsigned(unsigned int n)
{
	int		len;
	char	digit;

	len = 0;
	if (n > 9)
		len = len + ft_handle_nums(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
	len++;
	return (len);
}

int	ft_convert_base16(unsigned value, char *charset)
{
	int	len;

	len = 0;
	if (value >= 16)
		len = len + ft_convert_base16(value / 16, charset);
	write(1, &charset[value % 16], 1);
	len++;
	return (len);
}

static int	ft_convert_baseptr(size_t value, char *charset)
{
	int	len;

	len = 0;
	if (value >= 16)
		len = len + ft_convert_baseptr(value / 16, charset);
	write(1, &charset[value % 16], 1);
	len++;
	return (len);
}

int	ft_handle_ptr(void *ptr)
{
	int		len;
	size_t	ptrvalue;

	len = 0;
	ptrvalue = (size_t)ptr;
	if (ptr != NULL)
	{
		write(1, "0x", 2);
		len = ft_convert_baseptr(ptrvalue, "0123456789abcdef") + 2;
	}
	else
	{
		write(1, "0x0", 3);
		len = 3;
	}
	return (len);
}

int	ft_handle_nums(int n)
{
	int		len;
	char	digit;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	if (n > 9)
		len = len + ft_handle_nums(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
	len++;
	return (len);
}
