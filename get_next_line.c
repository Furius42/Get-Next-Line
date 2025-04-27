/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/27 18:30:04 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*compose_line(int fd);
char	*get_next_line(int fd)
{
	static fd_list	file_states; //array to hold FDs and the *l_next (pointer to next line) of that FD
	char			*l_next; 
	int				current_fd; //ssizet to accomodate -1 ??
	int				i;

	if (fd == 0)
		return (compose_line(0));
	i = 0;
	while(file_states.fd[i])
	{
		if (fd == file_states.fd[i++])
			printf("i = %i fd == file_states.fd[i]\n", i);
		//			l_next = compose_line(current_fd);
		else
		{
			file_states.fd[i] = fd;
			printf("filestates.fd[%i] set to %i\n", i, fd);
		}
	}
	return (l_next);
}

char	*compose_line(int fd)
{

	ssize_t		bytes_read;
	size_t		len;
	char		buf[BUFFER_SIZE];
	int			batch;
	char		*line;
	buf_node	*current;
	
	current = NULL;
	while (current)
	{
		read(fd,current->buf, BUFFER_SIZE - 1);
		// len = ft_strlen(current->buf)  ... . or ... if buffer fully loaded just add counter to batch, else use bytes_read
		line = parse(current->buf, line, len);
		current = current->next;
		++batch;
	}

	if (!(line = malloc(BUFFER_SIZE * batch + len + 1)))
		return (0);
}
