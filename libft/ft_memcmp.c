/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:25:46 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:47:55 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	str1[] = "Hello, World!";
	const char	str2[] = "Hello, everyone!";
	const char	str3[] = "Hello, World!";
	int	result;

	result = ft_memcmp(str1, str2, 5);
	printf("Comparaison de '%s' et '%s' (n=5): %d\n", str1, str2, result);

	result = ft_memcmp(str1, str2, 13);
	printf("Comparaison de '%s' et '%s' (n=13): %d\n", str1, str2, result);

	result = ft_memcmp(str1, str3, 13);
	printf("Comparaison de '%s' et '%s' (n=13): %d\n", str1, str3, result);

	return (0);
}*/