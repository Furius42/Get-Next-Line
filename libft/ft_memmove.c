/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:23:58 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:23:58 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (n--)
			*temp_dest++ = *temp_src++;
	}
	else if (dest > src)
	{
		temp_dest += n - 1;
		temp_src += n - 1;
		while (n--)
		{
			*temp_dest-- = *temp_src--;
		}
	}
	return (dest);
}
