/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/07 01:07:26 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

buf_node	*get_node(buf_node *current, int fd);
char	*compose_line(buf_node *current);
char	*get_next_line(int fd)
{
	static fd_list	*fd_buffers[MAX_FDS];//	array of buf_node heads for each FD (set max as pleased)

	return (compose_line(get_node(fd_buffers[0], fd))); // PASS HEAD TO COMPOSE_LINE TO BE ABLE TO ITERATE
}

buf_node	*get_node(fd_list list, int fd)
{
	int	i;

	i = 0;
	while (current)
	{
		if (current->fd == fd)
			return(current);
		else
			current = *fd_buffers[i]
	}
	return (node_ops(current, fd, 'a'));
}

char	*compose_line(buf_node *current)
{
char		*line;
int			bytes_read;
int			len;
buf_node 	*fd_head;

len = 0;
fd_head = current;
while (1)
{
bytes_read = read(current->fd, current->buf, BUFFER_SIZE - current->buf_len);
current->buf_len += bytes_read;
len += linelen(current->buf, '\n', current->buf_len); // line length limited by EOF(calculated) or determined by '\n' character

if (len = BUFFER_SIZE)// no \n found in this batch
	current = node_ops(current, current->fd, 'i');
}

current->buf_len = bytes_read - len;
line = malloc(len * sizeof(char) + 1);

current = fd_head;
while (len - BUFFER_SIZE > 0) 
	{
	ft_memcpy(line , current->buf, len);
	current =  node_ops(current, NULL, 'd');
	}
fd_head->buf_len = BUFFER_SIZE - (len % BUFFER_SIZE);	
return (line);
}

/*

//insert node
buf_node	*new_node;
new_node = malloc(sizeof(buf_node));

new_node->next = current->next;
current->next = node_ops(current->fd);


*/






while (bytes_read < BUFFER_SIZE) // read till EOF .. if read returns a value smaller than buffer size, it means there is EOF within the buffer.
	{
		len = linelen(current->buf, '\n', bytes_read);
		if (len < BUFFER_SIZE)
			if (line = malloc(sizeof(char) * len + 1))
	}


if (!(line = malloc(BUFFER_SIZE * batch_no + current->buf_len + 1)))
	return (0);

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