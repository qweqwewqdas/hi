/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:52:49 by duhkim            #+#    #+#             */
/*   Updated: 2025/04/18 00:42:28 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_start(const char *str, char const *set)
{
	int	i;
	int	start_i;

	i = 0;
	start_i = 0;
	while (set[i])
	{
		if (str[start_i] == set[i])
		{
			start_i++;
			i = 0;
		}
		else
			i++;
	}
	return (start_i);
}

static int	set_end(const char *str, char const *set)
{
	int	i;
	int	end_i;

	i = 0;
	end_i = ft_strlen(str);
	while (set[i])
	{
		if (str[end_i - 1] == set[i] && end_i != 0)
		{
			end_i--;
			i = 0;
		}
		else
			i++;
	}
	return (end_i);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*trimstr;
	int		start_i;
	int		end_i;

	start_i = set_start(str, set);
	end_i = set_end(str, set);
	if (start_i > end_i)
		return (ft_strdup(""));
	trimstr = (char *)malloc((end_i - start_i + 1) * sizeof(char));
	if (!trimstr)
		return (NULL);
	ft_strlcpy(trimstr, str + start_i, end_i - start_i + 1);
	return (trimstr);
}
