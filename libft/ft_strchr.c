/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:33:26 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:33:26 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

/*
#include <string.h>

char	*ft_strchr(const char *s, int c);

int		main(int argc, char* argv[])
{
	char *str;
	int chr;

//	if (argc != 3)
//		exit (0);
	str = "teste";
	chr = 'e';
	printf("ft_strchr output: %p\n", ft_strchr(str,chr));
	printf("strchr output: %p\n", strchr(str,chr));
	return (0);
}
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
