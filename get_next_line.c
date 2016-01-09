/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 13:45:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/09 12:39:29 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(int i, int size, char *buf, char **line)
{
	static char		*line1;
	static int		end = 0;
	char			*line2;
	int				k;

	k = 0;
	line2 = ft_strnew(size);
	if (end == 0)
	{
		line1 = ft_strnew(0);
		++end;
	}
	while (i < size && buf[i] != '\n')
	{
		line2[k] = buf[i];
		++i;
		++k;
	}
	line1 = ft_strjoin(line1, line2);
	if (buf[i] == '\n')
	{
		*line = ft_strdup(line1);
		free(line1);
		end = 0;
	}
	return (i);
}

int		get_next_line(int const fd, char **line)
{
	static char		*buf;
	static int		i = 0;
	static int		size = 0;

	if (i >= size)
	{
		if (buf)
			free(buf);
		if ((buf = (char*)malloc(sizeof(*buf) * BUF_SIZE)) == NULL)
			return (-1);
		if ((size = read(fd, buf, BUF_SIZE)) == -1)
			return (-1);
		i = 0;
	}
	while (i < size && buf[i] != '\n')
	{
		i = read_line(i, size, buf, line);
		if (i >= size)
		{
			if (buf)
				free(buf);
			if ((buf = (char*)malloc(sizeof(*buf) * BUF_SIZE)) == NULL)
				return (-1);
			if ((size = read(fd, buf, BUF_SIZE)) == -1)
				return (-1);
			i = 0;
		}
	}
	if (buf[i] == '\n' && i == 0)
		read_line(i, size, buf, line);
	if (buf[i] == '\n')
		++i;
	if (size != 0)
		return (1);
	return (0);
}
