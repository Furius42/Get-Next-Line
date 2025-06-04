/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:02:06 by vhoracek          #+#    #+#             */
/*   Updated: 2025/06/04 16:17:05 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;
	size_t	i;
	
	i = 0;
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
	while (i < total_size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
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

//Use following options:    Initialize: 'i';   Add: 'a';   Delete: 'd' 
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
