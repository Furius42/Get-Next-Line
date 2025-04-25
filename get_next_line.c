/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/25 13:19:08 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char *get_next_line(int fd)
{
	ssize_t	bytes_read;
	size_t	len;
	char	*next_line;
	char	buf[BUFFER_SIZE];
	typedef struct s_buffer
	{
		char			buff[BUFFER_SIZE];
		struct s_buffer	*next;
	}	t_node;
	t_node *current;

	current = NULL;
	while (current)
	{
		
		current = current->next;
	}
	
	next_line = read(fd, buf, len);
	return (next_line);
}
//linked lists, static struct to hold fd and next line start pointer

typedef struct s_fd {
    int fd;             // File descriptor
    char *next_line;    // Pointer to the start of the next line
} t_fd;

// Static array to store states for multiple file descriptors
static t_fd file_states[1024];  // assuming we can handle up to 1024 open files

