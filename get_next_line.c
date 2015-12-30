/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 13:45:26 by rfriscca          #+#    #+#             */
/*   Updated: 2015/12/30 16:06:00 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char		*buf = (char*)malloc(sizeof(*buf) * BUF_SIZE + 1);
	static int		end = 0;

	if (*buf == '\0')
	{
		end = read(fd, buf, BUF_SIZE);
		buf[end] = '\0';
	}
}