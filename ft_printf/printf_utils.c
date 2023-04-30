/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:04:31 by ykissiko          #+#    #+#             */
/*   Updated: 2022/11/20 12:49:59 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(char *str)
{
	int	i;

	if (!str)
		return (ft_str("(null)"));
	i = 0;
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_numbase(long n, int l, char *base)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= l)
	{
		len += ft_numbase(n / l, l, base);
		len += ft_numbase(n % l, l, base);
	}
	else
		len += write(1, &base[n], 1);
	return (len);
}

int	ft_ptr(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_ptr(n / 16);
	if ((n % 16) <= 9)
		len += ft_char((n % 16) + 48);
	else
		len += ft_char((n % 16) + 87);
	return (len);
}
