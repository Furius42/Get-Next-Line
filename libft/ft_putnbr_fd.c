/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:30:20 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:30:20 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr_rec(int n, int fd)
{
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_rec(n / 10, fd);
	write (fd, &"0123456789"[n % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else if (fd < 0)
		return ;
	ft_putnbr_rec(n, fd);
}
