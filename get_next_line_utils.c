/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:22:08 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/11/24 17:11:46 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	if (!str)
	{
		if (!(dest = (char*)malloc(sizeof(char))))
			return (NULL);
		*dest = '\0';
		return (dest);
	}
	if (!(dest = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *str, char *buffer)
{
	int		i;
	int		len;
	char	*dest;

	if (!str)
		return (ft_strdup(buffer));
	len = ft_strlen(str) + ft_strlen(buffer);
	if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	while (*buffer)
		dest[i] = *buffer++;
	dest[i] = '\0';
	free(str);
	return (dest);
}

int		len_to_endl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*split_back(char *str)
{
	int		i;
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * len_to_endl(str) + 1)))
		return (NULL);
	i = 0;
	while (i < len_to_endl(str))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*save_end(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	while (str[i + j])
		j++;
	if (!(dest = (char*)malloc(sizeof(char) * j)))
		return (NULL);
	j = 0;
	while (str[++i])
	{
		dest[j] = str[i];
		j++;
	}
	dest[j] = '\0';
	free(str);
	return (dest);
}
