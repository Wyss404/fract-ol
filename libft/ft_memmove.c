/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:07:46 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:48:11 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (dest_ptr < src_ptr)
	{
		while (n--)
		{
			*dest_ptr++ = *src_ptr++;
		}
	}
	else
	{
		dest_ptr += n;
		src_ptr += n;
		while (n--)
		{
			*--dest_ptr = *--src_ptr;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int	main()
{
	char src1[] = "bonjour le monde";
	ft_memmove(src1 + 3, src1, 2);
	printf("%s", src1);
	return (0);
}*/