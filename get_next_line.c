/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/04 23:26:07 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

buf_node	*get_node(buf_node *current, int fd);
char	*compose_line(buf_node *current);

char	*get_next_line(int fd)
{
	static buf_node	*head;//	array to hold FDs and the *l_next (pointer to next line) of that FD

	return (compose_line(get_node(head, fd))); // PASS HEAD TO COMPOSE_LINE TO BE ABLE TO ITERATE
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
	return (node_ops(current, fd, 'a'));
}

char	*compose_line(buf_node *current)
{
char		*line;
int			batch_no;
int			bytes_read;
int			len;

batch_no = 0; // if (len % BUFFER_SIZE ==  0 && len / BUFFER_SIZE != 0 ) {}
while (1)
{
bytes_read = read(current->fd, current->buf, BUFFER_SIZE - current->buf_len);
current->buf_len += bytes_read;
len = linelen(current->buf, '\n', current->buf_len); // line length limited by EOF(calculated) or determined by '\n' character

if (len = BUFFER_SIZE || len < )// no \n found in this batch
	current = node_ops(current, current->fd, 'i');
	batch_no ++;
}

current->buf_len = bytes_read - len;
line = malloc(len * batch_no * sizeof(char) + 1);
while (batch_no --)
	ft_memcpy(line + (BUFFER_SIZE * batch_no)/*invert*/, current->buf, len);
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