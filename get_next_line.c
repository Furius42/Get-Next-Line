/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/06/14 01:47:52 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

t_buf_node	*get_node(t_fd_list *fd_buffers, int fd)
{
	printf("get node\n");
	t_fd_list	*current_list;

	current_list = fd_buffers;
//	if (NULL == current)
//		return (node_ops(current, fd, 'i'));
	while (current_list->head->fd != fd)
	{
		if (!(current_list->next))
		{
			current_list = fd_list_ops(current_list, fd, 'a');
			return (current_list->head);
		}
		current_list = current_list->next;
	}
	return (current_list->head);
}

//returns LEN
ssize_t	read_into_buf(t_buf_node *current)
{
	int		i;
	ssize_t	len;
	int		b_read;

	len = 0;
	while (1)
	{
		b_read = read(current->fd, current->buf + current->buf_len,
				BUFFER_SIZE - current->buf_len);
		current->buf_len += b_read;
		i = linelen(current->buf, '\n', current->buf_len);
		if (i == 0)
		{
			len += current->buf_len;
			if ((current->buf_len == 0 && b_read == 0) || b_read < 0)
				return (-!(node_ops(current, current->fd, 'd')));
			if (current->buf_len == BUFFER_SIZE)
				current = node_ops(current, current->fd, 'a');
		}
		else
			return (len += i);
	}
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
		if (!(current->next))
		{
			printf("Copy %li chars to fd_head->buf: %p from current.buf+(len%%BUFFER_SIZE): %p \n", fd_head->buf_len, fd_head->buf, current->buf + (len % BUFFER_SIZE));
			ft_memcpy(fd_head->buf, current->buf + (len % BUFFER_SIZE), fd_head->buf_len);
			printf("fd_head->buf:\n%s^-- Leftover.buf len:%li\n", fd_head->buf, fd_head->buf_len);
			fd_head->next = NULL;
			line[len] = '\0';
		}
		if (current != fd_head)
			current = node_ops(current, current->fd, 'd');
		else
			current = current->next;
		i++;
	}
	return (line);
}

char	*compose_line(t_buf_node *current)
{
	printf("compose line\n");
	char		*line;
	ssize_t		len;
	t_buf_node	*fd_head;

	fd_head = current;
	len = read_into_buf(fd_head);
	if (len == -1)
		return (NULL);
	fd_head->buf_len -= (BUFFER_SIZE * !(len % BUFFER_SIZE)) + (len % BUFFER_SIZE);//eded curr to hed
	line = malloc(len * sizeof(char) + 1);
	if (NULL == line)
		return (NULL);
	printf("Current = %p, LinePtr = %p len = %li\n", current, line, len);
	return (parse_line(line, current, len));
}

char	*get_next_line(int fd)
{
	static t_fd_list	*fd_buffers;
	t_buf_node			*node;
	char				*line;

	if (fd_buffers == NULL)
		fd_buffers = fd_list_ops(NULL, fd, 'i');
	
	node = get_node(fd_buffers, fd);
	line = compose_line(node);
	if (NULL == line)
		fd_list_ops(fd_buffers, fd, 'd');
	return (line);
}
