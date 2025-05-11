/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:03:29 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/11 16:25:17 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// structure //

ssize_t	bytes_read;

Function receives FD
	->	Check if FD is valid
	look up if FD is in list 
		not in list	->	list_newline -> New FD * Start of file = NEXTLINE_START // go to next line -v
		is in list	->	take last NEXTLINE_START

Call FILL BUFFER
scan for '\n' or EOF (NULL) //function from libft.. . ?
	if not found, REPEAT(Call FILL BUFFER)

while(node.next[i++])
	if(node.next[i] != '\n')
		fill_buffer();

while(node.next[i] != '\n' || NULL != node.next[i])
	i++;



int	fill_buffer(int fd);
	while(node.next){
		bytes_read = read(fd, node_current->buffer, BUFFER_SIZE); // how to tell read from which character it should start reading???????? how to pass char *line_start??
		if (bytes_read <= 0) // no error handling. EOF = 0, ERROR = -1
			return (NULL);
	}
char	*parse_buffer(char* line, int line_len)


line = malloc(sizeof(char) * fill_buffer(fd_list.fd, fd_list.start));

return(parse_buffer(line, last_line_len));




typedef struct s_fd_buffer {
    int fd;
    char buffer[BUFFER_SIZE + 1];  // +1 for null-termination safety
    ssize_t buf_len;
    ssize_t buf_pos;
    struct s_fd_buffer *next;
} buf_node;

buf_node fd_list;

fd_list = NULL;

int fd = 0;
current = add_node(fd);

main -> get_next_line(fd)

get_next_line(fd)
	fd <= 0 ? return(NULL) : return(compose_line(get_node(fd)));

buf_node	*get_node(int fd)
{
	while (fd != current->fd)
		current = current.next;
	if (current->next == NULL)
		current->next = add_node(fd)
}

// ! !! KEEP track of available space in buf for next read (buf_free)

/* 
while (bytes_read < BS) // read till EOF .. if read returns a value smaller than buffer size, it means there is EOF within the buffer.
	{
		len = linelen(current->buf, '\n', bytes_read);
		if (len < BS)
			if (line = malloc(sizeof(char) * len + 1))
	}
 */
/* read from fd till \0 or BS.if \0 not found, make new node, repeat(batch++). once \0 found, alloc line(depending on number of itterations + read return val (bytes_read )) and return
	while (current)
	{
		read(fd,current->buf, BS - 1);
		// len = ft_strlen(current->buf)  ... . or ... if buffer fully loaded just add counter to batch, else use bytes_read
		line = parse(current->buf, line, len);
		
		current = current->next;
		++batch;
	}

	if (!(line = malloc(BS * batch + len + 1)))
		return (0);
	//iterate linked list and parse buffer batches-- 
*/
