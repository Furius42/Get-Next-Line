/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:54:27 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/04 22:25:12 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

# include <stdlib.h>	// malloc, free
# include <stddef.h>	// size_t
# include <stdio.h>		// printf
# include <unistd.h>	// read
# include <errno.h>		// errno
# include <fcntl.h>		// file open flags

typedef struct s_fd_buffer {
    int fd;
    char buf[BUFFER_SIZE + 1];  // +1 for null-termination safety
    ssize_t buf_len;
    ssize_t buf_pos;
    struct s_fd_buffer *next;
} buf_node;


char	*get_next_line(int fd);
char	*compose_line(buf_node *current);
size_t	ft_strlen(const char *s);
char	*parse(char *dst, const char *src, size_t dstsize);

#endif
