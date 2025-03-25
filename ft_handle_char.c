/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:50:42 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/25 13:21:11 by fbraune          ###   ########.fr       */
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
