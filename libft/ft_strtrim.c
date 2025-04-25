/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:42:22 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:42:22 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set);

int	main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Input 1/ String to be trimmed 2/ Charset to trim");
		return(2);
	}

	char* result = ft_strtrim(argv[1],argv[2]); 
	printf("%s\n", result);
	free(result);
	return 0;
}
*/
static int	tail(int s_len, char const *s, char const *set)
{
	const char	*set_o = set;
	int			i;

	i = s_len -1;
	while (i >= 0 && *set)
	{
		while (*set)
		{
			if (s[i] == *set)
			{
				i--;
				set = set_o;
			}
			else
				set++;
		}
	}
	return (i);
}

static int	nose(int s_len, char const *s, char const *set)
{
	const char	*set_o = set;
	int			i;

	i = 0;
	while (i <= s_len && *set)
	{
		while (*set)
		{
			if (s[i] == *set)
			{
				i++;
				set = set_o;
			}
			else
				set++;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const int	i = ft_strlen(s1);
	const int	n = nose(i, s1, set);
	const int	t = tail(i, s1, set);
	const int	len = t - n + 1;
	char		*string;

	if (n == i || t == 0)
	{
		string = malloc(sizeof(char));
		if (string == NULL)
			return (NULL);
		*string = '\0';
		return (string);
	}
	string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	ft_strlcpy (string, s1 + n, (len + 1));
	return (string);
}
