/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:23:47 by fatkeski          #+#    #+#             */
/*   Updated: 2023/12/25 19:54:55 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_strdup(char *arr)
{
	size_t	i;
	char	*new_line;

	new_line = (char *)malloc(sizeof(char) * (gnl_strlen(arr) + 1));
	if (new_line == 0)
		return (0);
	i = 0;
	while (arr[i] != '\0')
	{
		new_line[i] = arr[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*gnl_strjoin(char *arr, char *buff)
{
	char	*new_arr;
	size_t	i;
	size_t	j;

	if (arr == 0)
		arr = gnl_strdup("");
	new_arr = (char *)malloc(sizeof(char) * (gnl_strlen(arr) + gnl_strlen(buff)
				+ 1));
	if (new_arr == 0)
		return (0);
	i = 0;
	while (arr[i] != '\0')
	{
		new_arr[i] = arr[i];
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
		new_arr[i++] = buff[j++];
	new_arr[i] = '\0';
	free(arr);
	return (new_arr);
}
