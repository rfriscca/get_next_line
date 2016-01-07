/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 13:45:26 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/07 14:17:02 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		line[0][i] = buf[i];
		++i;
		if (i == size)
		{
			if ((size = read(fd, buf, BUF_SIZE)) == -1)
				return (-1);
			i = 0;
		}
	}
	if (size == 0)
		return (0);
	return (1);
}
