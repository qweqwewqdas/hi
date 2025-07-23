/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:10:23 by duhkim            #+#    #+#             */
/*   Updated: 2025/04/18 15:03:31 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t len)
{
	unsigned char	*s_ptr;
	unsigned char	find;

	s_ptr = (unsigned char *)ptr;
	find = (unsigned char)value;
	while (len--)
	{
		if (*s_ptr == find)
		{
			return (s_ptr);
		}
		s_ptr++;
	}
	return (NULL);
}
