/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:26:13 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:47:41 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr++ = 0;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[20] = "Hello, World!";

	printf("Avant ft_bzero : %s\n", str);

	ft_bzero(str, 6);

	printf("Après ft_bzero : %s\n", str);

	return (0);
}*/