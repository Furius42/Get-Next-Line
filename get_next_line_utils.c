/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:02:06 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/29 18:04:55 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (NULL == dest && NULL == src && n > 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*compose_line(int fd)
{

	ssize_t		bytes_read;
	size_t		len;
	char		buf[BUFFER_SIZE];
	buf_node	*current;

	current = NULL;
	while (current)
	{
		
		current = current->next;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*parse(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
			dst[i] = src[i++];
	}
	return (dst[i]);
}

buf_node	*add_node()
{
	buf_node	*node;
	
	node = malloc(sizeof(buf_node));
	if (node == NULL)
		return (1);
	node->next = NULL;
	return (node);
}
