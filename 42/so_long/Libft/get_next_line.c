/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:10:56 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/20 15:22:33 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_join_free(char *buffer, char *buf)
{
	char	*temp;

	temp = gnl_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*gnl_next(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = gnl_calloc((gnl_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*gnl_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (gnl_strchr(buffer, '\n'))
		line = gnl_calloc(i + 2, sizeof(char));
	else
		line = gnl_calloc(i + 1, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	*buf;
	int		byte_read;

	if (!buffer)
		buffer = gnl_calloc(1, 1);
	buf = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buf);
			free(buffer);
			return (NULL);
		}
		buf[byte_read] = '\0';
		buffer = gnl_join_free(buffer, buf);
		if (gnl_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || !gnl_strchr(buffer, '\n'))
		buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = gnl_line(buffer);
	buffer = gnl_next(buffer);
	return (line);
}
