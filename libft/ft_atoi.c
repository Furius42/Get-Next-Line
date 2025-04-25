/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:20:26 by vhoracek          #+#    #+#             */
/*   Updated: 2025/02/04 19:23:15 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Input one number");
		return (2);
	}
	printf("My atoi: %d\n", ft_atoi(argv[1]));
	printf("Da atoi: %d\n", atoi(argv[1]));
}
*/

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}
