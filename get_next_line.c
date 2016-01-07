/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 13:45:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/07 15:36:22 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(int i, int size, char **line, char *buf)
{
	char	*line1;

	line1 = (char*)malloc(sizeof(*line1) * size);
	while (buf[i] != '\n' && buf[i])
	{
		line1[i] = buf[i];
		++i;
	}
	if ((*line = ft_strjoin(*line, line1)) == NULL)
		return (-1);
	return (i);
}

int		get_next_line(int const fd, char **line)
{
	static char		*buf = (char*)malloc(sizeof(*buf) * BUF_SIZE);
	static int		i = 0;
	static int		size = 0;

	if (i == size)
		if ((size = read(fd, buf, BUF_SIZE)) == -1)
			return (-1);
	while (buf[i] != '\n' && size != 0)
	{
		if ((i = read_line(i, size, line, buf)) == -1)
			return (-1);
		if (i == size)
		{
			if ((size = read(fd, buf, BUF_SIZE)) == -1)
				return (-1);
			i = 0;
		}
	}
	++i;
	if (size == 0)
		return (0);
	return (1);
}
