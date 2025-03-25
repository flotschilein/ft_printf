/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:39:39 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/25 15:41:08 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_handle_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		write(1, "(NULL)", 6);
	if (!str)
		return (6);
	while (str[len] != '\0')
		len++ ;
	write(1, str, len);
	return (len);
}

int ft_convert_base16(size_t value, char *charset)
{
	int len;

	len = 0;
	if(value >= 16)
		len = len + ft_convert_base16(value / 16 , charset);
	write(1, &charset[value % 16],1);
	len++;

	return(len);
}

int ft_handle_ptr(void *ptr)
{
	int 	len;
	size_t	ptrvalue;

	len = 0;
	ptrvalue = (size_t)ptr;
	if(ptr != NULL)
	{
		write(1, "0x", 2);
		len = ft_convert_base16(ptrvalue, "0123456789abcdef");
	}
	else
	{
		write(1, "(NIL)",5);
		len = 5;
	}
	return(len);
}

int	ft_handle_nums(long int n)
{
	int	len;
	char digit;

	len = 0;
	if (n < 0)
	{
		write(1, '-', 1);
		n = -n;
		len++;
	}
	if (n > 9)
		len = len + ft_handle_nums(n / 10);
	digit = (n% 10) + '0';
	write(1, &digit, 1);
	len++;
	return (len);
}
