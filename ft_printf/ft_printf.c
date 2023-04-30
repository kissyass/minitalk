/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:33:25 by ykissiko          #+#    #+#             */
/*   Updated: 2022/11/10 15:33:27 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_char(va_arg(args, int));
	else if (format == 's')
		len += ft_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_numbase(va_arg(args, int), 10, "0123456789");
	else if (format == 'u')
		len += ft_numbase(va_arg(args, unsigned int), 10, "0123456789");
	else if (format == 'x')
		len += ft_numbase(va_arg(args, unsigned int), 16, "0123456789abcdef");
	else if (format == 'X')
		len += ft_numbase(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
	else if (format == 'p')
	{
		len += ft_str("0x");
		len += ft_ptr(va_arg(args, unsigned long));
	}
	else if (format == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_form(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_form(str[++i]))
			len += ft_formats(args, str[i]);
		else if (str[i])
			len += write(1, &str[i], 1);
		else
			break ;
		i++;
	}
	va_end(args);
	return (len);
}
