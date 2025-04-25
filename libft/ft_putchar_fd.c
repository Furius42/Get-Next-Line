/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:29:35 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:29:35 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <fcntl.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd);
int	main(void)
{
	int		fd;

	// Open a file for writing
	fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("File opening failed");
		return (1);
	}

	// Write to the file
	ft_putchar_fd('A', fd);
	close(fd);

	// Write to standard output
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);

	return (0);
}
*/

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
