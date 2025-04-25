/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:22:20 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:22:20 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>
#include <stddef.h>

int	ft_memcmp( unsigned char *str1, unsigned char *str2, size_t n);

int	main(int arg_c, char** arg_v){
	int	x;
	unsigned char	*in1;
	unsigned char	*in2;

	if (arg_c != 4)
		printf("str 1, str 2 , n");
	in1 = (unsigned char*)arg_v[1];
	in2 = (unsigned char*)arg_v[2];
	x = ft_memcmp( in1, in2, atoi(arg_v[3]));
printf ("%d\n", x );
return (0);
}
*/

int	ft_memcmp( unsigned char *str1, unsigned char *str2, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if ((str1[i] - str2[i]) != 0)
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
