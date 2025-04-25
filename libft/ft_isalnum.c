/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:15:47 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:15:47 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int c);

int	main(void){

	unsigned char i = 0;
while ( i < 128){
	printf("Int i = %d \n",i);
	printf("my isalnum: %d\n", ft_isalnum( i));
	printf("DA isalnum: %d\n", isalnum( i));
	i++;
	}
	return(0);
}
*/
int	ft_isalnum(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (4);
	else
		return (0);
}
