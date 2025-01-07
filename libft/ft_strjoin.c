/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:02:37 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 21:00:45 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2 + 1);
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*result;

	str1 = "Hello, ";
	str2 = "world!";
	result = ft_strjoin(str1, str2);
	if (result)
	{
		printf("Résultat de ft_strjoin : %s\n", result);
		free(result);
	}
	else
		printf("Erreur : la fonction ft_strjoin a échoué\n");
	return (0);
}*/
