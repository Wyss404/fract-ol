/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:42:58 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:48:41 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}
/*
#include <stdio.h>

int main(void)
{
	char *str1 = "Hello, World!";
	char *str2 = 0;

	ft_putstr_fd(str1, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(str2, 1);
	return (0);
}*/