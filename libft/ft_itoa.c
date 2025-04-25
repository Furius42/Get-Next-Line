/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:17:58 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:17:58 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>

static int	count_digits(int n);
static char	*handle_negative(int n, char *str, int len);
char	*ft_itoa(int n);

int main(void)
{
	char	*result;

	result = ft_itoa(0);
	if (result)
	{
		printf("Result: %s\n", result);
		free(result);
	}
	return (0);
}
*/

// Count digits
static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

// Handle negative numbers and convert
static char	*handle_negative(int n, char *str, int len)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	str[len] = '\0';
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = count_digits(n);
	str = (char *)calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (handle_negative(n, str, len));
}
