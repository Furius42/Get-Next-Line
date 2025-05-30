/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/20 18:20:03 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static fd_list	*fd_list_ops(fd_list *current, int fd, char option)
{
	fd_list	*node;

	if (option == 'd') // delete current, return pointer to the current->next
	{
		node = current->next;
		free (current);
		return (node);
	}
	node = calloc(1, sizeof(fd_list));// fill with zeros
	if (NULL == node)
		return (NULL);
	node->head = node_ops(NULL, fd, 'i');
	if (option == 'i')// INITIALIZE Head Node 
		node->next = NULL;
	else if (option == 'a')// APPEND Node / insert
	{
		node->next = current->next;
		current->next = node;
	}
	return (node);
}
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
static char	*compose_line(buf_node *current)
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
	i = 0;
	fd_head = current;
	copy_len = 0;
	// load buffer(s)
	while ((bytes_read = read(current->fd, current->buf + current->buf_len, BS - current->buf_len)) > 0)
	{
		current->buf_len += bytes_read;
		len += linelen(current->buf, '\n', current->buf_len); // line length limited by EOF(calculated) or determined by '\n' character

		if (len % BS == 0)// IF Buffer loaded in full since no \n nor EOF found in this batch
			current = node_ops(current, current->fd, 'a');//append node, set it to current if buffer fully loaded, no EOF nor \n found
		else//Found \n or EOF in this node->buf
			break;
	}
	if ((current->buf_len == 0 && bytes_read == 0) || bytes_read < 0 )// Check: read FAIL or EOF
		return ((char*)node_ops(current, current->fd, 'd')); // delete node head on EOF or FAIL
	current->buf_len = bytes_read - len % BS; // Set the size of future head's buffer to accomodate characters remaining after line extraction.
	if(!(line = malloc(len * sizeof(char) + 1)))
		return (NULL);
	current = fd_head;
	while (i * BS < len) 
		{
		copy_len = (len % BS) + (BS - (len % BS)) * (len / BS > i);
		ft_memmove(line + BS * i, current->buf, copy_len);
		if(i == len / BS)
		{
			ft_memmove(fd_head->buf, current->buf + (len % BS), current->buf_len);
			fd_head->buf_len = current->buf_len;
		}
		current = node_ops(current, current->fd, 'd');
		i++;
		}
	line[len] = '\0';
	return (line);
}


/*

Correct Flow (Reversed — Delete After)
Here’s how you can do it safely:

c
Copy
Edit
current = fd_head;
while (i * BS < len)
{
	int copy_len = (i == len / BS) ? len % BS : BS;
	ft_memmove(line + BS * i, current->buf, copy_len);

	if (i == len / BS) // Last buffer — move leftovers before deleting
	{
		ft_memmove(fd_head->buf, current->buf + (len % BS), current->buf_len);
		fd_head->buf_len = current->buf_len;
	}

	current = node_ops(current, current->fd, 'd'); // Safe now
	i++;
}

*/

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
