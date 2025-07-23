/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:10:28 by duhkim            #+#    #+#             */
/*   Updated: 2025/05/20 16:40:01 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(unsigned int n, char hex_digits[])
{
	int		len;
	int		sub;
	char	c;

	len = 0;
	if (n >= 16)
	{
		sub = print_number(n / 16, hex_digits);
		if (sub == -1)
			return (-1);
		len += sub;
	}
	c = hex_digits[n % 16];
	if (ft_print_char(c) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_hex(unsigned int value, int case_type)
{
	int		len;
	char	*type;

	len = 0;
	if (value == 0)
	{
		if (ft_print_char('0') != 1)
			return (-1);
		return (1);
	}
	if (case_type == 'a')
		type = "0123456789abcdef";
	else
		type = "0123456789ABCDEF";
	len += print_number(value, type);
	return (len);
}
