/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:13:50 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/11/24 13:11:45 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*line = NULL;

	if ((fd = open("main.c", O_RDONLY) < 0))
	{
		fprintf(stderr, "Could not open file\n");
		return (-1);
	}
	get_next_line(fd, &line);
	//printf("%s\n", line);
	/*get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);*/
	close(fd);
	return (0);
}
