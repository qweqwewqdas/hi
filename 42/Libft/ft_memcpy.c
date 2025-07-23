/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:06:29 by duhkim            #+#    #+#             */
/*   Updated: 2025/04/18 15:55:12 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *p, size_t len)
{
	unsigned char	*ptr;
	unsigned char	*src;
	size_t			i;

	ptr = (unsigned char *)dest;
	src = (unsigned char *)p;
	i = 0;
	if (len == 0 || ptr == src)
		return (dest);
	else if (ptr == NULL && src == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = src[i];
		i++;
	}
	return (dest);
}
