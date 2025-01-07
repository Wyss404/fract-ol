/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:57:10 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:48:37 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	digit = (n % 10) + '0';
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &digit, 1);
}
/*
int	main(void)
{
	int num = -12345;
	int num2 = -2147483648;

	ft_putnbr_fd(num, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(num2, 1);
	write(1, "\n", 1);
    return (0);
}*/
