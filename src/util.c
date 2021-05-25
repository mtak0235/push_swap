/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:39:44 by mtak              #+#    #+#             */
/*   Updated: 2021/05/24 14:15:35 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void		ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void		sort_int_tab_des(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	size--;
	while (i < size)
	{
		if (tab[i] < tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void		ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*elem;

	elem = *alst;
	while (elem->next)
		elem = elem->next;
	elem->next = new;
	return ;
}

t_list		*ft_lstnew_str(char *content)
{
	t_list	*tmp;
	int		i;
	char	*arr;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
		return (tmp);
	}
	arr = malloc(sizeof(char) * ft_strlen(content) + 1);
	i = 0;
	while (content[i])
	{
		arr[i] = content[i];
		i++;
	}
	arr[i] = '\0';
	tmp->content = (void *)arr;
	tmp->next = NULL;
	return (tmp);
}
