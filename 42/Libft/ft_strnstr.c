/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:11:08 by duhkim            #+#    #+#             */
/*   Updated: 2025/04/17 15:26:29 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	if (*src == '\0')
	{
		return ((char *)s);
	}
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		if (s[i] == src[0])
		{
			j = 0;
			while (src[j] != '\0' && s[i + j] == src[j] && (i + j) < len)
			{
				j++;
			}
			if (src[j] == '\0')
			{
				return ((char *)s + i);
			}
		}
		i++;
	}
	return (NULL);
}
