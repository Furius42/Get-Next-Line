/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:51:14 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/28 23:38:18 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct struct_node
{
	ssize_t				fd;
	char				line[BUFFER_SIZE];
	struct struct_node	*next;
}						t_node;

t_node	*add_node(ssize_t fd)
{
	t_node	*node;
	
	node = malloc(sizeof(node));
	node->fd = fd;
	node->next = NULL;
	return (node);
}

int	main(int argc, char *argv[])
{
	t_node	*root;
	t_node	*current;
	int		i;

	if (argc != 2)
		return(printf("Give 1 argument: File name to get next line from. Else lorem will be used.\n\n"));
	
	open("lorem.txt", O_RDONLY);
	open("new.txt", O_RDONLY);
	
	i = 0;
	root = malloc(sizeof(t_node));
	root->fd = 0;
	read(3, root->line, 1023);
	current = root;
	printf("Root.fd = %li \n",root->fd);
	while( 2 >= i )
	{
		current->next = add_node(3 + i);
		current = current->next;
		strcpy(current->line, argv[1]);
		i++;
	}

	current = root;
	i = 0;
	while (current)
	{
		printf("Node_addy %p fd = %li line = %s\n", current, current->fd, current->line);
		current = current->next;
	}
	/*
	int	*str;

	str = NULL;
	
	if(NULL == (str = malloc(sizeof(str) * atoi(argv[1]))));
		return (0);
*/
	sleep(100);
	return (0);
}
