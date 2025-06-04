/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/06/04 16:17:32 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

// UPDATE FOR LINKED LIST !! NOW IT IS WRITTEN FOR ARRAY.. 
static buf_node	*get_node(fd_list *fd_buffers, int fd)
{
	printf("get node\n");
	buf_node	*current;
	current = fd_buffers->head;
	if ( NULL == current )
		return (node_ops(current, fd, 'i'));
	while (current)
	{
		if (current->fd == fd)
			{
/* 			if (current->buf == 0)
				return(node_ops(current, fd, 'd'));
			else */
				return(current);
			}
		else
			current = fd_buffers->head->next;
	}
	return (node_ops(current, fd, 'i'));
}
// should this be static ?  NORME SAYS YES :D
char	*compose_line(buf_node *current)
{
	printf("compose line\n");
	char		*line;
	int			bytes_read;
	int			len;
	int			i;
	int			BS;
	int			copy_len;
	buf_node 	*fd_head;
	BS = BUFFER_SIZE;
	len = 0;
	fd_head = current;
	copy_len = 0;
	// load buffer(s)
	while ((bytes_read = read(current->fd, current->buf + current->buf_len, BS - current->buf_len)) > 0)
	{
		printf("Read of: %i/%li from FD%i to %p\n", bytes_read, (BS - current->buf_len), current->fd, current->buf + current->buf_len);
		current->buf_len += bytes_read;
		i = linelen(current->buf, '\n', current->buf_len); // line length limited by EOF(calculated) or determined by '\n' character
		if (i == 0)// Buffer loaded in full no \n found
			{
			len += current->buf_len;
			if(current->buf_len == BS)
				current = node_ops(current, current->fd, 'a');//append node, set it to current if buffer fully loaded, no EOF nor \n found
			}
		else// Found \n
			{
			len += i;
			break;
			}
	}
	i = 0;
	if ((current->buf_len == 0 && bytes_read == 0) || bytes_read < 0 )// Check: read FAIL or EOF
		{
			node_ops(current, current->fd, 'd');
			printf("FAIL OR EOF");
			return (NULL); // delete node head on EOF or FAIL
		}
	current->buf_len -= (BS * !(len % BS) + (len % BS)); //current->buf_len = bytes_read - len % BS;  Set the size of future head's buffer to accomodate characters remaining after line extraction.
	
	if(!(line = malloc(len * sizeof(char) + 1)))
		return (NULL);
	current = fd_head;
	printf("Current = %p len = %i\n", current, len);
	while (i * BS < len) 
		{
		copy_len = (len % BS) + (BS - (len % BS)) * (len / BS > i);
		ft_memcpy(line + BS * i, current->buf, copy_len);
		if(!(current->next)) //last node in chain if line longer than BUFFER_SIZE
		{
			printf("Copy %li chars to current.buf: %p from current.buf+(len%%BS): %p \n", current->buf_len, current->buf, current->buf + (len % BS));
			ft_memcpy(current->buf, current->buf + (len % BS), current->buf_len);
			printf("Current.buf:\n%s^-- Leftover.buf len:%li\n", current->buf, current->buf_len);
			if(current != fd_head)
				ft_memcpy(fd_head, current, sizeof(buf_node));
			line[len] = '\0';
			return (line);
		}
		//(current == fd_head && (current = current->next)) || (current = node_ops(current, current->fd, 'd'));
		if(current != fd_head)
			current = node_ops(current, current->fd, 'd');
		else
			current = current->next;
		i++;
		}
}

char	*get_next_line(int fd)
{
	char		*line;
	static		fd_list	*fd_buffers;//[MAX_FDS];//	array of buf_node heads for each FD (set max as pleased)
	buf_node	*node;

	if (fd_buffers == NULL)
		fd_buffers = fd_list_ops(NULL, fd, 'i');
	node = get_node(fd_buffers, fd);
	printf("step\n");
	line = compose_line(node);
	return (line); // PASS HEAD TO COMPOSE_LINE TO BE ABLE TO ITERATE // return (compose_line(get_node(fd_buffers, fd)));
}
