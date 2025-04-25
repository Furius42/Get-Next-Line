/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:28:13 by vhoracek          #+#    #+#             */
/*   Updated: 2025/03/18 12:28:13 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>
char	*ft_bitoa(long long int n, int base);

int main(int argc, char* argv[])
{
	char	*result;
	long	long int num;
	char	base;

	if (argc != 3 || atoi(argv[2]) > 36 || atoi(argv[2]) < 2)
		return (printf("Give 2 Args:\nDecimal input\nTarget base(2-36)\n"));
	num = atoi(argv[1]);
	base = atoi(argv[2]);
	result = ft_bitoa(num, base);
	if (result)
	{
		printf("\nConvert decimal:\n%s\nresults:\n%s", argv[1], result);
		printf(" in base %i\nat address:%p\n", base, &result);
		free(result);
	}
	return (0);
}
*/

static int	count_digits(unsigned long long int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

static char	*decimal(unsigned long long int n, char *str, int len)
{
	unsigned long long int	num;

	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	num = n;
	str[len] = '\0';
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

static char	*convert(unsigned long long int n, char *str, int len, int base)
{
	unsigned long long int	num;
	static char				*chars;

	chars = "0123456789abcdefghijklmnopqrstuvwxyz";
	num = n;
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = chars[(num % base)];
		num /= base;
	}
	return (str);
}

char	*ft_bitoa(unsigned long long int n, int base)
{
	char	*str;
	int		len;

	len = 0;
	len = count_digits(n, base);
	str = (char *)calloc(len + 1, sizeof(char));
	if (!str || base > 36 || base < 2)
		return (NULL);
	if (base == 10)
		return (decimal(n, str, len));
	else
		return (convert(n, str, len, base));
}
