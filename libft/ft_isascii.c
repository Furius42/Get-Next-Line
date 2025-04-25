/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:16:29 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:16:29 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c);

int	main(void){

	unsigned char i = 0;
while ( i < 128){
	if(ft_isascii( i) != isascii( i))
		printf("Char %d isascii returns %d \n",i, isascii( i));
	i++;
	}
	return(0);
}

*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
