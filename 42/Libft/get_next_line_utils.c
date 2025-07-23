/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:25:01 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/19 21:37:30 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_len = gnl_strlen(s1) + gnl_strlen(s2);
	res = malloc(sizeof(char) * (total_len + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[total_len] = '\0';
	return (res);
}

char	*gnl_strchr(const char *string, int search)
{
	char	*str;

	str = (char *)string;
	while (*str != search && *str != '\0')
		str++;
	if (*str == search)
		return (str);
	else
		return (NULL);
}

void	gnl_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*gnl_calloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	gnl_bzero(res, size * count);
	return (res);
}

size_t	gnl_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}
