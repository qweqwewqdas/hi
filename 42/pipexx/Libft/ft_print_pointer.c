/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:55:48 by duhkim            #+#    #+#             */
/*   Updated: 2025/05/05 17:58:21 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(unsigned long n)
{
	char	*hex;
	char	c;
	int		ret;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ret = print_hex(n / 16);
		if (ret == -1)
			return (-1);
	}
	c = hex[n % 16];
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_print_pointer(unsigned long value)
{
	int	len;

	if (value == 0)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) != 2)
		return (-1);
	len = 2;
	if (print_hex(value) == -1)
		return (-1);
	while (value)
	{
		value /= 16;
		len++;
	}
	return (len);
}
