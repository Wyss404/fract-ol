/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:54:30 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/16 18:48:34 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s != 0)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
		write(fd, "\n", 1);
	}
}
/*
#include <stdio.h>

int main(void)
{
	char *str1 = "Hello, World!";
	char *str2 = 0;
	char *str3 = "oui oui oui";

	ft_putendl_fd(str1, 1);
	ft_putendl_fd(str2, 1);
	ft_putendl_fd(str3, 1);
	return (0);
}*/