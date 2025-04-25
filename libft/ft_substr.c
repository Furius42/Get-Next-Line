/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:42:48 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:42:48 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	char	*str_start;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len <= start)
	{
		string = malloc(sizeof(char));
		if (string == NULL)
			return (NULL);
		*string = '\0';
		return (string);
	}
	if (start + len > str_len)
		len = str_len - start;
	string = malloc(len + 1);
	if (string == NULL )
		return (NULL);
	str_start = string;
	while (len--)
		*string++ = s[start++];
	*string = '\0';
	return (str_start);
}
