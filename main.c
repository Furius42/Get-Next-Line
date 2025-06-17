/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:14:23 by vhoracek          #+#    #+#             */
/*   Updated: 2025/06/17 23:14:05 by vhoracek         ###   ########.fr       */
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
	char	*line2;
	char	*line3;

	int		fd;
	int		fd3;
	int		fd2;
	
	if (argc != 2)
		return(printf("Give 1 argument: File name to get next line from or '0' for STDIN. Else lorem will be used.\n\n"));
	input = argv[1];
	if (*input == '0')
		fd = 0;
	else 
	{
	fd = open(input, O_RDONLY);
	fd2 = open("end.txt", O_RDONLY);
	fd3 = open("lorem.txt", O_RDONLY);
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
	int j = 1;
	int k = 1;
	while(i < 30)
	{
//		if (!line)//&& !line2 && !line3
//			break;
		line = get_next_line(fd);
		printf("\033[32;1mThis is FD3 line %i:\033[0m\n\033[30;1m%s\033[0m|\n", i++, line);
		free(line);/*
		if(line2 = get_next_line(fd2)){
			printf("\033[35;1mThis is FD4 line %i:\033[0m\n\033[30;1m%s\033[0m|\n", j++, line2);
			free(line2);}

		if(line3 = get_next_line(fd3)){
			printf("\033[34;1mThis is FD5 line3 %i:\033[0m\n\033[30;1m%s\033[0m|\n", k++, line3);
			free(line3);}*/
	}
	close(fd);
	close(fd2);
	close(fd3);
	printf("==FINISHED==\n");
	return (0);
}
