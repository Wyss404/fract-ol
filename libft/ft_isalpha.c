/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:04:13 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/17 16:25:57 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	int c1 = '4';
	int c2 = ' ';
	int c3 = 70;

	printf("%d\n",ft_isalpha(c1));
	printf("%d\n",ft_isalpha(c2));
	printf("%d\n",ft_isalpha(c3));
	return (0);
}*/