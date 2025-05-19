/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:54:27 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/19 14:00:32 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

/*
#ifndef MAX_FDS
# define MAX_FDS 1024//	per process soft limit in Linux is 1024 // 
#endif*/


# include <stdio.h>		// REMOVE DEBUG ONLY // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


# include <stdlib.h>	// malloc, free
# include <stddef.h>	// size_t
# include <unistd.h>	// read

typedef struct s_fd_buffer {
	int					fd;
	char				buf[BUFFER_SIZE];
	ssize_t				buf_len;
	struct s_fd_buffer	*next;
} buf_node;

typedef struct s_fd_list {
	buf_node			*head;
	struct s_fd_list	*next;
} fd_list;

char			*get_next_line(int fd);

void			*ft_memset(void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
buf_node		*node_ops(buf_node *current, int fd, char option);
size_t			linelen(const char *s, char term, size_t max_len);


#endif
