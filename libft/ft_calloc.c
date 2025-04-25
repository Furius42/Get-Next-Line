/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:19:00 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:19:00 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // size_t
#include "libft.h"
/*
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size);

void printAllocatedMemory(void* ptr, size_t num_elements, size_t element_size) {
	// Print the allocated memory
	printf("Allocated Memory:\n");
	for (size_t i = 0; i < num_elements * element_size; ++i) {
		printf("%d ", ((unsigned char*)ptr)[i]);
	}
	printf("\n");

	// Print one additional character beyond the allocated memory
	printf(" + %d\n", ((unsigned char*)ptr)[num_elements * element_size]);
}

int main(int argc, char* argv[]) {
	// Check for the correct number of command line arguments
	if (argc != 3) {
		printf("Usage: %s <num_elements> <element_size>\n", argv[0]);
		return 1;
	}

	// Parse command line arguments
	size_t num_elements = atoi(argv[1]);
	size_t element_size = atoi(argv[2]);

	// Allocate memory for an array of elements
	void* my_array = ft_calloc(num_elements, element_size);

	// Check if memory allocation is successful
	if (my_array != NULL) {
		// Print the allocated memory and one extra character beyond it
		printAllocatedMemory(my_array, num_elements, element_size);

		// free the allocated memory 
		free(my_array);
	} else {
		// Handle memory allocation failure
		printf("Memory allocation failed.\n");
	}

	return 0;
}
*/
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
