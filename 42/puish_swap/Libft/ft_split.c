/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:33:22 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/09 21:17:14 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_dup(const char *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (n == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**free_all(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (NULL);
}

static size_t	word_count(char const *s, char c)
{
	size_t	list_size;
	size_t	i;

	i = 0;
	list_size = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			list_size++;
		else if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			list_size++;
		i++;
	}
	return (list_size);
}

char	**ft_split(char const *s, char c)
{
	char	**str_list;
	size_t	i;
	size_t	k;
	size_t	save;

	i = 0;
	k = 0;
	str_list = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!str_list)
		return (NULL);
	while (i < word_count(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		save = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		str_list[i] = ft_dup(&s[save], k - save);
		if (str_list[i++] == 0)
			return (free_all(str_list));
	}
	str_list[i] = NULL;
	return (str_list);
}
