/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/11 16:25:05 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

buf_node	*get_node(fd_list *fd_buffers, int fd);
char	*compose_line(buf_node *current);
char	*get_next_line(int fd)
{
	static fd_list	*fd_buffers[MAX_FDS];//	array of buf_node heads for each FD (set max as pleased)

	return (compose_line(get_node(fd_buffers, fd))); // PASS HEAD TO COMPOSE_LINE TO BE ABLE TO ITERATE
}

buf_node	*get_node(fd_list *fd_buffers, int fd)
{
	int			i;
	buf_node	*current;
	i = 0;
	current = fd_buffers[i].head;
	while (current && i < MAX_FDS)
	{
		if (current->fd == fd)
			return(current);
		else
			current = fd_buffers[++i].head;
	}
	return (node_ops(current, fd, 'i'));
}

char	*compose_line(buf_node *current)
{
	char		*line;
	int			bytes_read;
	int			len;
	int			i;
	int			BS;

	buf_node 	*fd_head;

	BS = BUFFER_SIZE;
	len = 0;
	i = 0;
	fd_head = current;
	while ((bytes_read = read(current->fd, current->buf, BS - current->buf_len)) > 0)
	{
		current->buf_len += bytes_read;
		len += linelen(current->buf, '\n', current->buf_len); // line length limited by EOF(calculated) or determined by '\n' character

		if (len % BS == 0)// IF Buffer loaded in full since no \n nor EOF found in this batch
			current = node_ops(current, current->fd, 'a');//append node, set it to current if buffer fully loaded, no EOF nor \n found
		else//Found \n or EOF in this node->buf
			break;
	}

	current->buf_len = bytes_read - len % BS; // Set the size of future head's buffer to accomodate characters remaining after line extraction.
	if(!(line = malloc(len * sizeof(char) + 1)))
		return (NULL);

	current = fd_head;
	while (i * BS < len) 
		{
		ft_memcpy(line + BS * i++, current->buf, (len % BS) + (BS - (len % BS)) * (i < len / BS));
		current = node_ops(current, NULL, 'd');
		}
	ft_memcpy(fd_head->buf, fd_head->buf + (len % BS), current->buf_len); //	move the rest of buff to zero
	line[len] = '\0';
	return (line);
}
