/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:27:56 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/17 16:57:32 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	str[] = "HelWlo, World!";
	char		*result;

	result = ft_strchr(str, 'W');
	if (result)
		printf("Le caractère 'W' a été trouvé : %s\n", result);
	else
		printf("Le caractère 'W' n'a pas été trouvé.\n");
	result = ft_strchr(str, 'z');
	if (result)
		printf("Le caractère 'z' a été trouvé : %s\n", result);
	else
		printf("Le caractère 'z' n'a pas été trouvé.\n");
	result = ft_strchr(str, '\0');
	if (result)
		printf("Le caractère nul '\\0' a été trouvé à la fin de la chaîne.\n");
	return (0);
}*/