/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:33:35 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/22 22:10:21 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

int main()
{
	int fd;
	char buf[128];
	ssize_t bytes_read;

	fd = open("file.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

	if (fd == -1)
	{
		perror("open failed");
		return (1);
	}
	printf("Spy activated, writing to fd: %i file.txt. CTRL+D to stop \n\n", fd);
	while ((bytes_read = read(0, buf, sizeof(buf))) > 0)
		write(fd, buf, bytes_read);
	close(fd);
	return (0);
}
