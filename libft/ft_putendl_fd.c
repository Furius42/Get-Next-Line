/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:29:47 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:29:47 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <fcntl.h>
#include <stdio.h>

void	ft_putendl_fd(char *s, int fd);

// Example to write a string to a file and standard output with a newline
int	main(void)
{
	int		fd;

	// Open a file for writing
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Open file failed");
		return (1);
	}

	// Write to the file
	ft_putendl_fd("Hello, file!", fd);
	close(fd);

	// Write to standard output
	ft_putendl_fd("Hello, terminal!", 1);

	return (0);
}
*/
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}
