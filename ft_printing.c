/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:39:39 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/25 20:10:23 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_handle_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return(ft_handle_str("(null)"));
	while (str[len] != '\0')
		len++;
	if(write(1, str, len) == -1)
		return (-1);
	return (len);
}
