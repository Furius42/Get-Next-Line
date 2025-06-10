/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:14:23 by vhoracek          #+#    #+#             */
/*   Updated: 2025/06/09 22:17:12 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "./get_next_line.h"

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
