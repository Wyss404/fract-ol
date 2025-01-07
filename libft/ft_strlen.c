/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:41:30 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/17 17:03:46 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
/*
#include <stdio.h>

int	main()
{
	const char *str1 = "oui c'est moi";
	const char *str2 = "et la aussi et je sais pas quoi ecrire j'ecris un truc";

	printf("%zu\n",ft_strlen(str1));
	return(0);
}*/