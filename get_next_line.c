/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:28:58 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/20 12:55:27 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buf	ft_realloc(int const fd, t_buf buf)
{
	if (buf.i == buf.size)
	{
		buf.i = 0;
		if (!buf.buf)
			if ((buf.buf = (char*)malloc(sizeof(*buf.buf) * BUF_SIZE)) == NULL)
				buf.i = -1;
		if ((buf.size = read(fd, buf.buf, BUF_SIZE)) == -1)
			buf.i = -1;
	}
	return (buf);
}

int		get_next_line(int const fd, char **line)
{
	static t_buf	buf;
	int				i;
	char			*save;

	i = 0;
	if (!line)
		return (-1);
	buf = ft_realloc(fd, buf);
	if (buf.i == -1 || (save = ft_strnew(BUF_SIZE)) == NULL ||
			(*line = ft_strnew(0)) == NULL)
		return (-1);
	while (buf.size)
	{
		if (buf.buf[buf.i] == '\n')
		{
			*line = ft_strjoin(*line, save);
			free(save);
			++buf.i;
			return (1);
		}
		save[i] = buf.buf[buf.i];
		++i;
		++buf.i;
		if (buf.i == buf.size)
		{
			*line = ft_strjoin(*line, save);
			ft_bzero(save, BUF_SIZE);
			i = 0;
		}
		buf = ft_realloc(fd, buf);
		if (buf.i == -1)
			return (-1);
	}
	return (0);
}
