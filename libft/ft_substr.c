/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:56:04 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/17 16:57:33 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // For malloc
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*source = "Hello, World!";
	char	*substring;

	substring = ft_substr(source, 7, 5);
	if (substring == NULL)
	{
		printf("Échec de l'allocation de mémoire.\n");
		return (1);
	}
	printf("Sous-chaîne extraite : %s\n", substring);
	free(substring);
	return (0);
}*/
