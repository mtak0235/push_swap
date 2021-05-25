/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:11:16 by mtak              #+#    #+#             */
/*   Updated: 2021/05/24 14:12:58 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char*)s;
	while (n > 0)
	{
		*(str++) = 0;
		n--;
	}
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(*list));
	if (!list)
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = malloc(content_size);
		if (!list->content)
		{
			free(list);
			return (NULL);
		}
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str;
	const unsigned char	*str2;

	str = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	if (!str && !str2)
		return (0);
	while (n > 0)
	{
		*(str++) = *(str2++);
		n--;
	}
	return (dst);
}
