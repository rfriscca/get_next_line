/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 13:45:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/13 16:39:07 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(t_buf buf, char **line)
{
	static char		*line1;
	static int		end = 0;
	char			*line2;
	int				k;

	k = 0;
	line2 = ft_strnew(buf.size);
	if (end == 0)
		line1 = ft_strnew(0);
	end = 1;
	while (buf.i < buf.size && buf.buf[buf.i] != '\n')
	{
		line2[k] = buf.buf[buf.i];
		++k;
		++buf.i;
	}
	line1 = ft_strjoin(line1, line2);
	if (buf.buf[buf.i] == '\n' || buf.size == 0)
	{
		*line = ft_strdup(line1);
		free(line1);
		end = 0;
	}
	return (buf.i);
}

t_buf	ft_realloc(int fd, t_buf buf)
{
	if (buf.i >= buf.size)
	{
		buf.i = 0;
		if (buf.buf)
			free(buf.buf);
		if ((buf.buf = (char*)malloc(sizeof(*buf.buf) * BUF_SIZE)) == NULL)
			buf.i = -1;
		if ((buf.size = read(fd, buf.buf, BUF_SIZE)) == -1)
			buf.i = -1;
	}
	return (buf);
}

t_buf	first_alloc(t_buf buf)
{
	if (buf.buf == NULL)
	{
		buf.i = 0;
		buf.size = 0;
	}
	return (buf);
}

int		get_next_line(int const fd, char **line)
{
	static t_buf	buf;
	int				flag;

	buf = first_alloc(buf);
	buf = ft_realloc(fd, buf);
	if (buf.i == -1)
		return (-1);
	flag = 1;
	while (buf.i < buf.size && buf.buf[buf.i] != '\n')
	{
		flag = 0;
		buf.i = read_line(buf, line);
		buf = ft_realloc(fd, buf);
		if (buf.i == -1)
			return (-1);
	}
	if ((buf.buf[buf.i] == '\n' && buf.i == 0))
		read_line(buf, line);
	if (buf.buf[buf.i] == '\n')
		++buf.i;
	if (buf.size != 0)
		return (1);
	if (flag == 0)
	{
		read_line(buf, line);
		flag = 1;
		return (1);
	}
	return (0);
}
