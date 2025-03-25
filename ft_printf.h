/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:13:30 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/25 15:10:58 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *, ...);

int		ft_handle_char(int c);

int		ft_handle_str(char *str);

int		ft_handle_ptr(void *ptr);

int 	ft_convert_base16(size_t value, char *charset);