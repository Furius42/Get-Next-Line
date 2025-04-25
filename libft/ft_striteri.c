/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:35:48 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:35:48 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

// Example function to capitalize characters at even indices
void	cap_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32; // Convert to uppercase
}

int	main(void)
{
	char	str[] = "hello world";

	printf("Original: %s\n", str);
	ft_striteri(str, example_function);
	printf("Modified: %s\n", str);
	return (0);
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
