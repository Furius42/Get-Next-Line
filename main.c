/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:52:57 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/24 16:01:55 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	main(int argc, char *argv[])
{
	char	*input;
	char	*line;
	int		fd;
	
	if (argc != 2)
		return(printf("Give 1 argument: File name to get next line from. Else lorem will be used.\n\n"));
	input = *argv[1];
	if (input == "0")
		fd = 0;
	else 
		{
		fd = open(input, O_RDONLY);
		if (fd == -1)
			{
			perror("Open failed. Falling back to lorem.txt");
			fd = open("lorem.txt", O_RDONLY);
				if (fd == -1)
					return(!!fprintf(stderr,"Error opening lorem.txt: %s\n",strerror(errno)));
			}
		}
			while((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free(line);
		}
	close(fd);
	return (0);
}

// testing git

// test
