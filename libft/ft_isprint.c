/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:30:56 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/17 16:57:59 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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

	printf("%d\n",ft_isprint(c1));
	printf("%d\n",ft_isprint(c2));
	printf("%d\n",ft_isprint(c3));
	printf("%d\n",ft_isprint(c4));
	return (0);
}*/