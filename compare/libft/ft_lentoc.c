/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lentoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 00:19:38 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/12 00:20:02 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lentoc(char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (len);
}