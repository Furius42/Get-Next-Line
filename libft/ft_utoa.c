/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:29:03 by vhoracek          #+#    #+#             */
/*   Updated: 2025/04/14 19:58:39 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
#include <stdio.h>
#include <ctype.h>
char	*ft_utoa(unsigned int n);

int		main(int argc, char* argv[])
{
	if (argc != 2)
		printf("Enter a single number(unsigned int)\n");
	printf("unsigned int: %u\n, (unsigned int)atol(argv[1]));
	printf("utoa output : %s\n", ft_utoa(atol(argv[1])));
	return (0);
}
*/
static int	count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*convert(unsigned int n, char *str, int len)
{
	str[len] = '\0';
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;

	len = count_digits(n);
	str = (char *)calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (convert(n, str, len));
}
