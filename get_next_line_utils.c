/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:02:06 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/11 16:35:02 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

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
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (NULL == dest || NULL == src && n > 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
// call with char term = 10 for '\n' || is limited by max_len. Keeping current buffer length as maximum
size_t	linelen(const char *s, char term, int max_len)
{
	size_t	len;

	len = 0;
	while (s[len] != term || len < max_len) // len <= max_len ??
		len++;
	return (len);
}


buf_node	*node_ops(buf_node *current, int fd, char option)
{
	buf_node	*node;

	if (option == 'd') // delete current, return pointer to the current->next
	{
		node = current->next;
		free (current);
		return (node);
	}
	node = calloc(1, sizeof(buf_node));// fill with zeros
	if (NULL == node)
		return (NULL);
	node->buf_len = BUFFER_SIZE;
	node->fd = fd;
	if (option == 'i')// INITIALIZE Head Node 
		node->next = NULL;
	else if (option == 'a')// APPEND Node / insert
	{
		node->next = current->next;
		current->next = node;
	}
	return (node);
}
