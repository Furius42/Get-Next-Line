/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:17:25 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:17:25 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c);

int	main(void){

	unsigned char i = 0;
while ( i < 127){
	if(ft_isprint( i) != isprint( i))
		printf("Char %d isprint returns %d \n",i, isprint( i));
	i++;
	}
	return(0);
}
*/
int	ft_isprint(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (4);
	else if ((c > 32 && c < 48) || (c > 57 && c < 97) || (c > 122 && c < 127))
		return (16);
	else if (c == 32)
		return (64);
	else
		return (0);
}
