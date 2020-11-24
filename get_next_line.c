/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:57:17 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/11/24 17:44:08 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		endline(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*create_line(char *line, char **str)
{
	if (endline(*str) == 0)
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	else
	{
		if (!(line = split_back(*str)))
			return (NULL);
		if (!(*str = save_end(*str)))
			return (NULL);
	}
	return (line);
	
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	int			nb_read;
	static char	*str[256];

	if (BUFFER_SIZE <= 0)
		return (-1);
	if (fd < 0 || !line || !(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (endline(str[fd]) == 0 && (nb_read = read(fd, buffer, BUFFER_SIZE)))
	{
		if (nb_read == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[nb_read] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
	}
	free(buffer);
	if (!(*line = create_line(*line, &str[fd])))
		return (-1);
	return (str[fd] == NULL && nb_read == 0 ? 0 : 1);
}
