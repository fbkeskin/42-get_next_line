/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:23:57 by fatkeski          #+#    #+#             */
/*   Updated: 2023/12/25 19:54:11 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_next_line(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

static char	*read_a_line(int fd, char *arr)
{
	int		bytes_read;
	char	buff[BUFFER_SIZE + 1];

	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		arr = gnl_strjoin(arr, buff);
		if (buff[find_next_line(buff) - 1] == '\n')
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		free(arr);
		return (0);
	}
	return (arr);
}

static char	*get_a_line(char *arr)
{
	char	*line;
	int		i;
	int		len;

	if (arr == 0)
		return (0);
	len = find_next_line(arr);
	i = 0;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == 0)
		return (0);
	while (i < len)
	{
		line[i] = arr[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

static char	*control_line(char *line)
{
	char	*arr;
	size_t	after_nl_index;

	if (line == 0)
		return (0);
	after_nl_index = find_next_line(line);
	if (line[after_nl_index] == '\0')
	{
		free(line);
		return (0);
	}
	arr = gnl_strdup(&line[after_nl_index]);
	free(line);
	return (arr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*arr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	arr = read_a_line(fd, arr);
	line = get_a_line(arr);
	arr = control_line(arr);
	return (line);
}
