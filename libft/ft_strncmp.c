/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:55:14 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 20:37:30 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <stdio.h>

int	main(void)
{
    char *str1 = "Hello, World!";
    char *str2 = "Hello, World!";
    char *str3 = "Hello, C!";
    char *str4 = "Hello";

    int result1 = ft_strncmp(str1, str2, 5);
    int result2 = ft_strncmp(str1, str3, 7);
    int result3 = ft_strncmp(str1, str4, 5);
    int result4 = ft_strncmp(str1, str4, 10);

    printf("ft_strncmp(\"%s\", \"%s\", 5) = %d\n", str1, str2, result1);
    printf("ft_strncmp(\"%s\", \"%s\", 7) = %d\n", str1, str3, result2);
    printf("ft_strncmp(\"%s\", \"%s\", 5) = %d\n", str1, str4, result3);
    printf("ft_strncmp(\"%s\", \"%s\", 10) = %d\n", str1, str4, result4);

    return 0;
}*/
