/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:32:51 by ykissiko          #+#    #+#             */
/*   Updated: 2022/11/20 12:48:11 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_formats(va_list args, const char format);
int	ft_form(char c);
int	ft_char(int c);
int	ft_str(char *str);
int	ft_numbase(long n, int l, char *base);
int	ft_ptr(unsigned long n);

#endif
