/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:04:32 by duhkim            #+#    #+#             */
/*   Updated: 2025/04/14 18:27:21 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int num, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)p;
	num = (unsigned char)num;
	i = 0;
	while (i < len)
	{
		ptr[i] = num;
		i++;
	}
	return (p);
}
