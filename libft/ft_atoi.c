/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:58:50 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:46:53 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
#include <stdio.h>

int	main()
{
	char	test1[] = " ---+--+1234ab567";
	char	test2[] = "   +42";
	char	test3[] = "-00123";
	char	test4[] = "42 with text";
	printf("Test 1: %d\n", ft_atoi(test1)); // -1234
	printf("Test 2: %d\n", ft_atoi(test2)); // 42
	printf("Test 3: %d\n", ft_atoi(test3)); // -123
	printf("Test 4: %d\n", ft_atoi(test4)); // 42
	return (0);
}*/
