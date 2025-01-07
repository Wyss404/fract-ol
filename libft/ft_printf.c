/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:11:48 by hdruel            #+#    #+#             */
/*   Updated: 2024/10/30 18:59:43 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uppercase(char *str)
{
	int		i;
	char	*result;

	if (!str)
		return (NULL);
	result = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			result[i] = str[i] - 32;
		else
			result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_puthex(unsigned long n, int uppercase)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (ft_putchar('0'));
	}
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	if (uppercase)
		count += ft_putchar("0123456789ABCDEF"[n % 16]);
	else
		count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_specifier(char specifier, va_list args)
{
	unsigned long	ptr;

	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (ptr == 0)
			return (ft_putstr("(nil)"));
		ft_putstr("0x");
		return (ft_puthex(ptr, 0) + 2);
	}
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_specifier(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int main()
{
    ft_printf("Test with null pointers: %p %p\n", 0, 0);
    return 0;
}*/
