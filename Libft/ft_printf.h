/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:57:02 by duhkim            #+#    #+#             */
/*   Updated: 2025/05/20 16:39:54 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	ft_print_pointer(unsigned long value);
int	ft_print_unsigned_int(unsigned int nb);
int	ft_print_string(char *s);
int	ft_print_int(int n);
int	ft_print_char(char c);
int	ft_print_hex(unsigned int value, int case_type);

#endif
