/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:57:20 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/11/24 13:17:38 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

char	*create_str(char *str, char *buffer);
int		endline(char *str);
size_t	ft_strlen(const char *s);

#endif
