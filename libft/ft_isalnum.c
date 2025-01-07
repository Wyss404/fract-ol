/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:20:29 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/17 16:25:56 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
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

	printf("%d\n",ft_isalnum(c1));
	printf("%d\n",ft_isalnum(c2));
	printf("%d\n",ft_isalnum(c3));
	return (0);
}*/
