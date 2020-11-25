/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:43:17 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/11/25 15:14:53 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
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
	if (dest == src)
		return (dest);
	d = (char*)dest;
	s = (char*)src;
	i = 0;
	if (d < s)
		while (n-- > 0)
			*d++ = *s++;
	else
		while (++i <= n)
			d[n - i] = s[n - i];
	return (dest);
}

int		find_endl(char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;
	char	*rtn;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	len = s1_len + s2_len;
	if (!(rtn = malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_memmove(rtn, s1, s1_len);
	ft_memmove(rtn + s1_len, s2, s2_len);
	rtn[len] = '\0';
	free((char *)s1);
	return (rtn);
}
