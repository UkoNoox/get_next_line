/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:22:08 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/11/24 13:20:04 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	if (d < s)
		while (n-- > 0)
			*d++ = *s++;
	else
		while (++i <= n)
			d[n - i] = s[n - i];
	return (dest);
}

char	*create_str(char *str, char *buffer)
{
	char	*dest;
	int		len;

	if (!str && !buffer)
		return (NULL);
	len = ft_strlen(str) + ft_strlen(buffer);
	if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_memmove(dest, str, ft_strlen(str));
	ft_memmove(dest + ft_strlen(str), buffer, ft_strlen(buffer));
	dest[len] = '\0';
	free(str);
	return (str);
}

int		endline(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}
