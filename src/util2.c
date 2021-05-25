/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:10:40 by mtak              #+#    #+#             */
/*   Updated: 2021/05/24 14:17:16 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

void			sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	size--;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void			*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

long long		ft_atoill(const char *str)
{
	int					i;
	unsigned long long	nb;
	int					p;

	i = 0;
	p = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		p = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = nb * p;
	return (nb);
}

int				ft_isblank(int c)
{
	return (c == ' ' || c == '\t');
}
