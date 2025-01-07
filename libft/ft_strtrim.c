/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:22:26 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/17 21:32:19 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // For malloc
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[end - start] = '\0';
	return (trimmed);
}
/*
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char	*result;
	char	*str = "   Hello, World!   ";
	char	*set = " ";

	result = ft_strtrim(str, set);
	if (!result)
	{
		write(2, "Échec de l'allocation de mémoire.\n", 35);
		return (1);
	}
	write(1, "Chaîne trimée : ", 17);
	write(1, result, ft_strlen(result));
	write(1, "\n", 2);
	free(result);
	return (0);
}*/
