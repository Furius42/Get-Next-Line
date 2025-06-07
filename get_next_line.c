/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/06/07 02:23:11 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

/*
	while (current)
	{
		if (current->fd == fd)
			if (current->buf == 0)
				return(node_ops(current, fd, 'd'));
			return(current);
		else
			current = fd_buffers->head->next;
	}
*/
// UPDATE FOR LINKED LIST !! NOW IT IS WRITTEN FOR ARRAY.. 
static t_buf_node	*get_node(t_fd_list *fd_buffers, int fd)
{
	printf("get node\n");
	t_buf_node	*current;
	current = fd_buffers->head;
	if ( NULL == current )
		return (node_ops(current, fd, 'i'));
	while (current)
	{
		if (current->fd == fd)
			return(current);
		else
			current = fd_buffers->head->next;
	}
	return (node_ops(current, fd, 'i'));
}

//returns LEN
ssize_t	read_into_buf(t_buf_node *current)
{
	int		i;
	ssize_t	len;
	int		b_read;

	len = 0;
	while ((b_read = read(current->fd, current->buf + current->buf_len,
			BUFFER_SIZE - current->buf_len)) > 0)
	{
		current->buf_len += b_read;
		i = linelen(current->buf, '\n', current->buf_len);
		if (i == 0)
		{
			len += current->buf_len;
			if(current->buf_len == BUFFER_SIZE)
				current = node_ops(current, current->fd, 'a');
		}
		else
		{
			len += i;
			break;
		}
	}
	if ((current->buf_len == 0 && b_read == 0) || b_read < 0 )
		return (-!(node_ops(current, current->fd, 'd')));
}
char	*parse_line(char *line, t_buf_node *fd_head, int len)
{
	int			i;
	int			copy_len;
	t_buf_node	*current;

	current = fd_head;
	i = 0;
	while (i * BUFFER_SIZE < len) 
	{
		copy_len = (len % BUFFER_SIZE) + (BUFFER_SIZE - (len % BUFFER_SIZE)) * (len / BUFFER_SIZE > i);
		ft_memcpy(line + BUFFER_SIZE * i, current->buf, copy_len);
		if(!(current->next))
		{
			printf("Copy %li chars to current.buf: %p from current.buf+(len%%BUFFER_SIZE): %p \n", current->buf_len, current->buf, current->buf + (len % BUFFER_SIZE));
			ft_memcpy(current->buf, current->buf + (len % BUFFER_SIZE), current->buf_len);
			printf("Current.buf:\n%s^-- Leftover.buf len:%li\n", current->buf, current->buf_len);
			if(current != fd_head)
				ft_memcpy(fd_head, current, sizeof(t_buf_node));
			line[len] = '\0';
			return (line);
		}
		if(current != fd_head)
			current = node_ops(current, current->fd, 'd');
		else
			current = current->next;
		i++;
	}
}

char	*compose_line(t_buf_node *current)
{
	printf("compose line\n");
	char		*line;
	ssize_t		len;
	int			i;
	int			copy_len;
	t_buf_node 	*fd_head;
	len = 0;
	fd_head = current;
	copy_len = 0;
	len = read_into_buf(fd_head);
	if (len == -1)
		return (NULL);
	i = 0;
	current->buf_len -= (BUFFER_SIZE * !(len % BUFFER_SIZE) + (len % BUFFER_SIZE));
	if(!(line = malloc(len * sizeof(char) + 1)))
		return (NULL);
	current = fd_head;
	printf("Current = %p len = %li\n", current, len);
	return (parse_line(line, current, len));
}

char	*get_next_line(int fd)
{
	char				*line;
	static t_fd_list	*fd_buffers;
	t_buf_node			*node;

	if (fd_buffers == NULL)
		fd_buffers = fd_list_ops(NULL, fd, 'i');
	node = get_node(fd_buffers, fd);
	printf("step\n");
	line = compose_line(node);
	return (line);
}
