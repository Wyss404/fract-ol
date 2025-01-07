/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:32:13 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/17 18:19:23 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_nbr_len(int n)
{
	int	len;

	len = (n <= 0) * 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = (n < 0);
	len = ft_nbr_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (is_negative)
		n = -n;
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
/*
#include <unistd.h>

int main(void)
{
	int number;
	char *result;

	number = -12345;
	result = ft_itoa(number);
	if (result)
	{
		write(1, result, ft_nbr_len(number));
		write(1, "\n", 1);
		free(result);
	}
	return (0);
}*/
