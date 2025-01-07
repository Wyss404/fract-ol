/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:18:40 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/17 16:57:57 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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

	printf("%d\n",ft_isdigit(c1));
	printf("%d\n",ft_isdigit(c2));
	printf("%d\n",ft_isdigit(c3));
	printf("%d\n",ft_isdigit(c4));
	return (0);
}*/