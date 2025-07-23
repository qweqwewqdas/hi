/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:27:51 by duhkim            #+#    #+#             */
/*   Updated: 2025/05/26 20:52:51 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	if (!s1 && !s2)
		return (0);
	if (n == 0)
		return (0);
	while (n--)
	{
		if (p1[i] != p2[i] || p1[i] == '\0' || p2[i] == '\0')
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
