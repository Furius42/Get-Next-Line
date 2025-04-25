/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:30:46 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:30:46 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <fcntl.h>
#include <stdio.h>

// Example to write a string to a file and standard output
void	ft_putstr_fd(char *s, int fd);
int	main(void)
{
	int		fd;

	// Open a file for writing
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("File opening failed");
		return (1);
	}

	// Write to the file
	ft_putstr_fd("Hello, file!\n", fd);
	close(fd);

	// Write to standard output
	ft_putstr_fd("Hello, terminal!\n", 1);

	return (0);
}
*/
void	ft_putstr_fd(char *s, int fd)
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
}
