/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:02:06 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/28 01:21:05 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "./get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_size); // copy the function code here to save one function
	return (ptr);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (n--)
			*temp_dest++ = *temp_src++;
	}
	else if (dest > src)
	{
		temp_dest += n - 1;
		temp_src += n - 1;
		while (n--)
		{
			*temp_dest-- = *temp_src--;
		}
	}
	return (dest);
}
// Returns length including character specified in char term. If not found returns 0
size_t	linelen(const char *s, char term, size_t max_len)
{
	size_t	len;

	len = 0;
	while (s[len] != term && len < max_len)
		len++;
	if (len == max_len)
		return (0); /// ale kurva i kdyz bude EOF !!! vraci NULU
	return (++len);
}


buf_node	*node_ops(buf_node *current, int fd, char option)
{
	buf_node	*node;

	if (option == 'd') // delete current, return pointer to the current->next
	{
		node = current->next;
		printf("node at %p deleted\n", current);
		free (current);
		return (node);
	}
	node = calloc(1, sizeof(buf_node));// fill with zeros
	if (NULL == node)
		return (NULL);
	node->fd = fd;
	if (option == 'i')// INITIALIZE Head Node 
	{
		node->next = NULL;
		printf("node initialized at %p\n", node);
	}
	else if (option == 'a')// APPEND Node / insert
	{
		node->next = current->next;
		current->next = node;
		printf("node added at %p\n", node);
	}
	return (node);
}


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
	if ((current->buf_len == 0 && bytes_read == 0) || bytes_read < 0 )// Check: read FAIL or EOF
		{
			node_ops(current, current->fd, 'd');
			printf("FAIL OR EOF");
			return (NULL); // delete node head on EOF or FAIL
		}
	current->buf_len -= len % BS; //current->buf_len = bytes_read - len % BS;  Set the size of future head's buffer to accomodate characters remaining after line extraction.
	
	if(!(line = malloc(len * sizeof(char) + 1)))
		return (NULL);
	current = fd_head;
	printf("Current = %p len = %i\n", current, len);
	while (i * BS < len) 
		{
		copy_len = (len % BS) + (BS - (len % BS)) * (len / BS > i);
		ft_memcpy(line + BS * i, current->buf, copy_len);
		if(i == len / BS) //last node in chain if line longer than BUFFER_SIZE
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


// fuck it and start over again//////////////////////////////////////////////////////////////////////////////////////////////////////
/*
buf_node	*clean_up_nodes(buf_node *current) // free and return NULL ?? why do i need it ? I dont
{
while(current->next)
	current = node_ops(current, current->fd, 'd');
return(current);
}
char	*parse_line(buf_node *current)//?what should it return? THE LINE! ! 
{

}

char	*compose_line(buf_node *current)// ////////////////////////////// NEW COMPOSE LINE //////////////
{
	ssize_t	bytes_read;
	size_t	len;
	char	*line;
	printf("compose line\n");
//	Read Into Buffer
while(1)
{
	while (current)
	{
	bytes_read = read(current->fd, current->buf + current->buf_len, BUFFER_SIZE - current->buf_len);
	len += linelen(current->buf, '\n', BUFFER_SIZE);
	current = current->next;
	}
}
//	Scan for \n or EOF -ADD NODE, Reapeat till found. KEEP TRACK OF NODES ? 


//	Calculate Line Length, allocate and copy from buffer(s)
line = parse_line(current);

//	Copy Remainder of buffer to the beginning of Head node, set buffer size

//	Clean up extra nodes if there are any
clean_up_nodes(current);

//	Return Line
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

int	main(int argc, char *argv[])
{
	char	*input;
	char	*line;
	int		fd;
	
	if (argc != 2)
		return(printf("Give 1 argument: File name to get next line from or '0' for STDIN. Else lorem will be used.\n\n"));
	input = argv[1];
	if (*input == '0')
		fd = 0;
	else 
	{
	fd = open(input, O_RDONLY);
	if (fd == -1)
		{
		fprintf(stderr, "Opening %s failed. Reason: %s\n", input, strerror(errno));
		fd = open("lorem.txt", O_RDONLY);
			if (fd == -1)
			{
				perror("Opening lorem.txt failed. Falling back to STDIN (fd 0). Reason");
				fd = 0;
			}
		}
	}
	int i = 1;
	while((line = get_next_line(fd)))
	{
		printf("\033[32;1mThis is line %i:\033[0m\n\033[30;1m%s\033[0m|\n", i++, line);
		free(line);
		if(i == 30)
			return(0);
	}
	close(fd);
	printf("==FINISHED==\n");
	return (0);
}

// copy the \n character !! !!