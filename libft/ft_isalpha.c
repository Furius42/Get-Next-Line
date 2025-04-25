/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:16:12 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:16:12 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c);

int	main(void){

	unsigned char i = 0;
while ( i < 128){
	if(ft_isalpha( i) != isalpha( i))
		printf("Char %d isalpha returns %d \n",i, isalpha( i));
	i++;
	}
	return(0);
}
*/

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else
		return (0);
}
