/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:13:35 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:47:51 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	str[] = "Hello, World!";
	char		*result;
	result = ft_memchr(str, 'o', sizeof(str));
	if (result)
		printf("Première occurrence de 'o' trouvée à : %s\n", result);
	else
		printf("Caractère 'o' non trouvé\n");
	result = ft_memchr(str, 'z', sizeof(str));
	if (result)
		printf("Première occurrence de 'z' trouvée à : %s\n", result);
	else
		printf("Caractère 'z' non trouvé\n");
	return (0);
}*/