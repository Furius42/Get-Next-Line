/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:38:47 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:38:47 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	char	*start;
	int		i;

	i = ft_strlen(s1) + ft_strlen(s2);
	cat = malloc((i + 1) * sizeof(char));
	start = cat;
	if (!cat)
		return (0);
	while (*s1)
	{
		*cat = *s1;
		cat++;
		s1++;
	}
	while (*s2)
	{
		*cat = *s2;
		cat++;
		s2++;
	}
	*cat = '\0';
	return (start);
}
