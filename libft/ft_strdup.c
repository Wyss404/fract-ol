/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:00:44 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:49:04 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // for malloc
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*dup;
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*source = "Bonjour, monde ?";
	char	*duplication;

	duplication = ft_strdup(source);
	if (duplication == NULL)
	{
		printf("Échec de l'allocation de mémoire.\n");
		return (1);
	}
	printf("Chaîne source : %s\n", source);
	printf("Chaîne dupliquée : %s\n", duplication);
	free(duplication);
	return (0);
}*/