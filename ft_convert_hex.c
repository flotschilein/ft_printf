/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:28:34 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/25 15:34:35 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
