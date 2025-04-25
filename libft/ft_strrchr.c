/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:41:26 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:41:26 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

int		main(int argc, char* argv[])
{
	char *str;
	int chr;

	if (argc != 3)
		return (2);
	str = argv[1];
	chr = *argv[2];
	printf("ft_strchr output: %p\n", ft_strrchr(str,chr));
	printf("strchr output: %p\n", strrchr(str,chr));
	return (0);
}
*/
char	*ft_strrchr(const char *s, int c)
{
	const char	*sx;

	sx = s;
	while (*sx)
		sx++;
	if ((unsigned char)c == 0)
		return ((char *)sx);
	while (s != sx--)
	{
		if (*sx == (unsigned char)c)
			return ((char *)sx);
	}
	return (0);
}
