/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printingnumbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:34:40 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/28 16:01:45 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_unsigned(unsigned int n)
{
	int		len;
	char	digit;
	int		res;

	len = 0;
	if (n > 9)
	{
		res = ft_handle_unsigned(n / 10);
		if (res == -1)
			return (-1);
		len = len + res;
	}
	digit = (n % 10) + '0';
	if (write(1, &digit, 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_convert_base16(unsigned int value, char *charset)
{
	int	len;
	int	res;

	len = 0;
	res = 0;
	if (value >= 16)
		res = ft_convert_base16(value / 16, charset);
	if (res == -1)
		return (-1);
	len = len + res;
	if (write(1, &charset[value % 16], 1) == -1)
		return (-1);
	len++;
	return (len);
}

static int	ft_convert_baseptr(size_t value, char *charset)
{
	int	len;
	int	res;

	len = 0;
	res = 0;
	if (value >= 16)
		res = ft_convert_baseptr(value / 16, charset);
	if (res == -1)
		return (-1);
	len = len + res;
	if (write(1, &charset[value % 16], 1) == -1)
		return (-1);
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
		if (write(1, "0x", 2) == -1)
			return (-1);
		len = ft_convert_baseptr(ptrvalue, "0123456789abcdef") + 2;
	}
	else
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		len = 3;
	}
	return (len);
}

int	ft_handle_nums(int n)
{
	int		len;
	int		res;

	len = 0;
	res = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (n < 0 && ++len == 1)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
		res = ft_handle_nums(n / 10);
	if (res == -1)
		return (-1);
	len = len + res;
	if (write(1, &(char){n % 10 + '0'}, 1) == -1)
		return (-1);
	return (len + 1);
}
