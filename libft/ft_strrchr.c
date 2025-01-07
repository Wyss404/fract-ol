/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:54:45 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:50:20 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence = 0;

	while (*s)
	{
		if (*s == (char)c)
			last_occurrence = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last_occurrence);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	str[] = "Hello, World!";
	char		*result;

	result = ft_strrchr(str, 'l');
	if (result)
		printf("Dernière occurrence de 'l' trouvée à : %s\n", result);
	else
		printf("Caractère 'l' non trouvé\n");
	result = ft_strrchr(str, 'z');
	if (result)
		printf("Dernière occurrence de 'z' trouvée à : %s\n", result);
	else
		printf("Caractère 'z' non trouvé\n");
	return (0);
}*/
