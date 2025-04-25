/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:40:41 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:40:41 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Example function: convert characters to uppercase at even indices
char	example_function(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32); // Convert to uppercase
	return (c);
}

int	main(void)
{
	char	*input = "Nabuchadonozor and Enki's Nam Shub";
	char	*result;

	result = ft_strmapi(input, example_function);
	if (result)
	{
		printf("Original: %s\n", input);
		printf("Modified: %s\n", result);
		free(result);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	unsigned int	len;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
