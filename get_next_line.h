/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:57:20 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/11/24 16:57:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

char	*split_back(char *str);
char	*ft_strjoin(char *str, char *buffer);
char	*ft_strdup(char *str);
char	*save_end(char *str);
int		ft_strlen(char *str);

#endif
