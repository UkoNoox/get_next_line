/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:57:17 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/11/24 13:18:32 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*dest;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(dest = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*str;
	int			read_value;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	read_value = 1;
	str = NULL;
	while (!endline(str) && read_value != 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[read_value] = '\0';
		str = create_str(str, buffer);
	}
	free(buffer);
	*line = get_line(str);
	return (read_value == 0 ? 0 : 1);
}
