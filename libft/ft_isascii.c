/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:54:31 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/17 16:57:55 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	int c4 = 500;

	printf("%d\n",ft_isascii(c1));
	printf("%d\n",ft_isascii(c2));
	printf("%d\n",ft_isascii(c3));
	printf("%d\n",ft_isascii(c4));
	return (0);
}*/