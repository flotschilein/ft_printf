/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:13:30 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/26 16:42:11 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_handle_char(int c);
int	ft_handle_str(char *str);
int	ft_handle_ptr(void *ptr);
int	ft_convert_base16(unsigned int value, char *charset);
int	ft_handle_nums(int n);
int	ft_handle_unsigned(unsigned int n);

#endif