/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:02:06 by vhoracek          #+#    #+#             */
/*   Updated: 2025/05/04 18:03:03 by vhoracek         ###   ########.fr       */
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
// call with char term = 10 for '\n' || is limited by max_len. Keeping current buffer length as maximum
size_t	linelen(const char *s, char term, int max_len)
{
	size_t	len;

	len = 0;
	while (s[len] != term || len < max_len) // len <= max_len ??
		len++;
	return (len);
}

char	*parse(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize > 0)//			see if norm takes it//
		while (i < dstsize - 1 && src[i] != '\0')
			dst[i] = src[i++];
	return (dst[i]);
}

buf_node	*add_node(fd)
{
	buf_node	*node;
	
	node = calloc(1, sizeof(buf_node));// fill with zeros
	if (NULL == node)
		return (1);
	node->buf_len = BUFFER_SIZE;
	node->next = NULL;
	node->fd = fd;
	return (node);
}
