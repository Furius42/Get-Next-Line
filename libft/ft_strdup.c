/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:34:43 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:34:43 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	duplicate = (char *)calloc((len + 1), sizeof(char));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (i < len)
	{
		duplicate[i] = s[i];
		i ++;
	}
	duplicate[len] = '\0';
	return (duplicate);
}
