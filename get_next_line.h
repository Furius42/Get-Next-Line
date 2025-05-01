/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:54:27 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/28 23:30:40 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

# include <stdio.h>		// printf
# include <unistd.h>	// read
# include <stdlib.h>	// malloc, free
# include <errno.h>		// errno
# include <stddef.h>	// size_t
# include <fcntl.h>

typedef struct
{
	int		fd[127];
	char	*l_start[127];
}fd_list;

typedef struct s_buffer
{
	char	buf[BUFFER_SIZE];
	struct	s_buffer	*next;
}buf_node;

char	*get_next_line(int fd);
char	*compose_line(int fd, char *start);
size_t	ft_strlen(const char *s);
char	*parse(char *dst, const char *src, size_t dstsize);

#endif
