/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:44:11 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/24 01:28:42 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // For malloc
#include <stddef.h>
#include "libft.h"

void	*ft_calloc(unsigned int count, size_t size)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)malloc(count * size);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int					*array;
	unsigned int		n;
	long unsigned int	i;

	n = 5;
	array = (int *)ft_calloc(n, sizeof(int));
	if (array == NULL)
	{
		printf("Échec de l'allocation de mémoire.\n");
		return (1);
	}
	for (i = 0; i < n; i++)
		printf("array[%zu] = %d\n", i, array[i]);
	free(array);
	return (0);
}*/
