/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 14:04:08 by rfriscca          #+#    #+#             */
/*   Updated: 2016/01/19 15:22:35 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE 0

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_buf
{
	char			*buf;
	int				fd;
	int				i;
	int				size;
}					t_buf;

#endif
