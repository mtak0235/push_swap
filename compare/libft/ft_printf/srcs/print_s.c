/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:29:38 by pvandamm          #+#    #+#             */
/*   Updated: 2021/05/22 07:57:32 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	split(int i, int length, t_flags flags, char *s)
{
	if (flags.precision > 0 && i)
	{
		while (flags.precision && *s)
		{
			ft_putchar(*s++);
			flags.precision--;
			length++;
		}
	}
	else if (flags.precision != -1)
	{
		ft_putstr(s);
		length += ft_strlen(s);
	}
	return (length);
}

int	print_s(va_list ap, t_flags flags)
{
	int		length;

	int		i;
	char	*s;
	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	i = ft_strlen(s);
	length = print_s_option(s, flags);
	length = split(i, length, flags, s);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}
