/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:18 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/24 12:40:30 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char *get_next_line(int fd)
{
	ssize_t	bytes_read;
	size_t	len;
	char	*next_line;
	char	buf[BUFFER_SIZE];
	
	next_line = read(fd, buf, len);
	return (next_line);
}
