/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:10:44 by duhkim            #+#    #+#             */
/*   Updated: 2025/04/18 15:03:33 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t len)
{
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;
	size_t			i;

	ptr_1 = (unsigned char *)ptr1;
	ptr_2 = (unsigned char *)ptr2;
	i = 0;
	while (i < len)
	{
		if (ptr_1[i] != ptr_2[i])
		{
			return (ptr_1[i] - ptr_2[i]);
		}
		i++;
	}
	return (0);
}
