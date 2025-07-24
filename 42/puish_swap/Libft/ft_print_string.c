/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:13:49 by duhkim            #+#    #+#             */
/*   Updated: 2025/05/20 16:47:49 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	unsigned int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len] != '\0')
		len++;
	return (write(1, str, len));
}
