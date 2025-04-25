/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:20:35 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:20:35 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n);

int	main(int argc, char* argv[]) {
	// Test 1: Simple test
	const char *str1 = argv[1];
	char target1 = *argv[2];
	size_t len1 = strlen(str1);

	void *result1 = ft_memchr(str1, target1, len1);
	if (result1) {
		printf("Found '%c' at position %ld\n", target1, (char*)result1 - str1);
	} else {
		printf("'%c' not found in the string.\n", target1);
	}

	// Test 2: Compare with standard memchr
	const char *str5 = "Testing memchr comparison";
	char target5 = 'm';
	size_t len5 = strlen(str5);

	void *result5 = ft_memchr(str5, target5, len5);
	void *std_result = memchr(str5, target5, len5);

	if (result5 == std_result) {
		printf("ft_memchr and memchr match.\n");
	} else {
		printf("ft_memchr and memchr do not match.\n");
	}

	return 0;
}
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;
	unsigned char			target;

	ptr = (const unsigned char *)s;
	target = (unsigned char)c;
	while (n)
	{
		if (*ptr == target)
			return ((void *) ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
