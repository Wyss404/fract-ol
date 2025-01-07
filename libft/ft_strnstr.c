/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:33:36 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:50:14 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*big = "Hello, World!";
	const char	*small = "World";
	const char	*not_found = "42";
	char		*result;

	result = ft_strnstr(big, small, 13);
	if (result)
		printf("Sous-chaîne trouvée: %s\n", result);
	else
		printf("Sous-chaîne non trouvée\n");
	result = ft_strnstr(big, not_found, 13);
	if (result)
		printf("Sous-chaîne trouvée: %s\n", result);
	else
		printf("Sous-chaîne non trouvée\n");
	result = ft_strnstr(big, small, 5);
	if (result)
		printf("Sous-chaîne trouvée: %s\n", result);
	else
		printf("Sous-chaîne non trouvée\n");
	return (0);
}*/