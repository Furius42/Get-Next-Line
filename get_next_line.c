/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/04 18:19:00 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

buf_node	*get_node(buf_node *current, int fd);
char	*compose_line(buf_node *current);

char	*get_next_line(int fd)
{
	static buf_node	*head;//	array to hold FDs and the *l_next (pointer to next line) of that FD

	return (compose_line(get_node(head, fd)));
}

buf_node	*get_node(buf_node *current, int fd)
{
	while (current)
	{
		if (current->fd == fd)
			return(current);
		else
			current = current->next;
	}
	return (add_node(fd));
}

char	*compose_line(buf_node *current)
{
char	*line;
int		batch;
int		bytes_read;
int		len;

bytes_read = read(current->fd,current->buf, BUFFER_SIZE - current->buf_len);
len = linelen(current->buf, '\n', bytes_read + current->buf_len);

while (len = BUFFER_SIZE)// no \n found in this batch
	add_line() = malloc(sizeof(char) * BUFFER_SIZE + 1); // if line longer than buffer - linked list or dynamic array??
	
current->buf_len = bytes_read - len;
line = malloc(len * batch * sizeof(char) + 1);
while (batch --)
	ft_memcpy(line + BUFFER_SIZE * batch/*invert*/, current->buf, len);
	return (line);















while (bytes_read < BUFFER_SIZE) // read till EOF .. if read returns a value smaller than buffer size, it means there is EOF within the buffer.
	{
		len = linelen(current->buf, '\n', bytes_read);
		if (len < BUFFER_SIZE)
			if (line = malloc(sizeof(char) * len + 1))
	}


if (!(line = malloc(BUFFER_SIZE * batch + current->buf_len + 1)))
	return (0);
}
/* read from fd till \0 or BUFFER_SIZE.if \0 not found, make new node, repeat(batch++). once \0 found, alloc line(depending on number of itterations + read return val (bytes_read )) and return
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
	//iterate linked list and parse buffer batches-- 
*/

load buff in full.  read(fd, buf, buf_free - 0)
take line...
move the rest of buff to zero
keep track of available space in buf for next read (buf_free)