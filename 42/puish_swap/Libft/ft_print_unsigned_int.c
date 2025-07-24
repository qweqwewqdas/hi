/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:01:25 by duhkim            #+#    #+#             */
/*   Updated: 2025/05/20 16:44:41 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_out(unsigned int num)
{
	if (num != 0)
	{
		print_out(num / 10);
		if (ft_print_char(num % 10 + '0') != 1)
			return (-1);
	}
	return (1);
}

int	ft_print_unsigned_int(unsigned int num)
{
	unsigned int	tmp;
	int				len;

	tmp = num;
	len = 0;
	if (num == 0)
	{
		if (ft_print_char('0') != 1)
			return (-1);
		return (1);
	}
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	if (print_out(num) == -1)
		return (-1);
	return (len);
}
