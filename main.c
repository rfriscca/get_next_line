/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:28:42 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/19 15:18:28 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (get_next_line(2, &line) == -1)
		ft_putstr("error\n");
	while (get_next_line(3, &line) > 0)
	{
		ft_putstr(line);
		ft_bzero(line, ft_strlen(line));
		ft_putchar('\n');
		usleep(500000);
	}
	return (0);
}
