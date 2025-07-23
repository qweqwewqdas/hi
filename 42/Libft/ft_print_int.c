/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:13:11 by duhkim            #+#    #+#             */
/*   Updated: 2025/05/20 16:44:51 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int n)
{
	int		len;
	int		sub;
	char	c;

	len = 0;
	if (n >= 10)
	{
		sub = ft_print_int(n / 10);
		if (sub == -1)
			return (-1);
		len += sub;
	}
	c = (n % 10) + '0';
	if (ft_print_char(c) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_int(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) != 11)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		n = -n;
		len++;
	}
	len += ft_print_number(n);
	return (len);
}
