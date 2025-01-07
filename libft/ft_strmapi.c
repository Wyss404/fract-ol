/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:50:09 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:50:00 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (0);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	to_upper(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c);
	else
		return (ft_toupper(c));
}

int	main(void)
{
	char	*str = "abcdef";
	char	*result;

	result = ft_strmapi(str, to_upper);
	if (result)
	{
		printf("Chaîne originale : %s\n", str);
		printf("Chaîne transformée : %s\n", result);
		free(result);
	}
	else
	{
		printf("Erreur lors de la transformation de la chaîne\n");
	}
	return (0);
}*/
