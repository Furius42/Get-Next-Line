/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:54:27 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/11 16:30:16 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#ifndef MAX_FDS
# define MAX_FDS 128//	per process soft limit in Linux is 1024 // 
#endif

# include <stdlib.h>	// malloc, free
# include <stddef.h>	// size_t
# include <stdio.h>		// printf
# include <unistd.h>	// read
# include <errno.h>		// errno
# include <fcntl.h>		// file open flags

typedef struct s_fd_buffer {
	int					fd;
	char				buf[BUFFER_SIZE];  // +1 for null-termination safety
	ssize_t				buf_len;
	struct s_fd_buffer	*next;
} buf_node;

typedef struct s_fd_list {
	buf_node *head;
} fd_list;

void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*get_next_line(int fd);
buf_node	*get_node(fd_list *fd_buffers, int fd);
char		*compose_line(buf_node *current);
buf_node	*node_ops(buf_node *current, int fd, char option);
size_t		linelen(const char *s, char term, int max_len);

#endif
