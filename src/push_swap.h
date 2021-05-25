/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:06:16 by mtak              #+#    #+#             */
/*   Updated: 2021/05/24 14:21:20 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define NO_MED 2147483648
# define BRED "\033[1;31m"
# define BBLUE "\033[1;34m"
# define DEFAULT "\033[0m"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lstnum
{
	long			n;
	struct s_lstnum	*next;
	struct s_lstnum	*prev;
}					t_lstnum;

typedef struct		s_stack
{
	t_lstnum		*head;
	t_lstnum		*end;
	t_lstnum		**p;
	int				top;
	int				ac;
}					t_stack;

void				parse_nb_from_first_str(t_stack *a, char *str);
void				parse_nb_from_second_str(t_stack *a, char *str);
void				print_stacks(t_lstnum *a, t_lstnum *b);

void				ft_error(void);
void				build_stack(t_stack *a, int ac, char **av, int flag);
void				swapper(t_stack *a, t_stack *b, char *line, int *flag);
void				swap(t_lstnum **stack);
void				push(t_lstnum **from, t_lstnum **to, t_lstnum **to_end);
void				ft_rotate(t_lstnum **head, t_lstnum **end);
void				rotater(t_stack *a, t_stack *b, char *line, int *flag);
void				ft_reverse_rotate(t_lstnum **head, t_lstnum **end);
void				reverse_rotater(t_stack *a, t_stack *b,\
char *line, int *flag);

t_list				*solve(t_stack *a, t_stack *b);
int					get_count(t_stack *stack);
int					get_true_median(t_stack *a);
void				split_from_med_a(t_stack *a, t_stack *b,\
int med, char *solut);
int					get_special_median_a(t_stack *a);
void				sort_a(t_stack *a, int count, char *solution);
int					get_special_median_b(t_stack *b);
void				split_from_med_b(t_stack *a, t_stack *b,\
int med, char *solut);
void				sort_b(t_stack *b, int count, char *tmp);

void				ft_memdel(void **ap);
void				ft_putstr_fd(char const *s, int fd);
int					ft_isdigit(int c);

void				sort_int_tab_des(int *tab, unsigned int size);
void				ft_lstadd_end(t_list **alst, t_list *new);
t_list				*ft_lstnew_str(char *content);
char				*ft_strcat(char *s1, const char *s2);
void				sort_int_tab(int *tab, unsigned int size);
void				*ft_memalloc(size_t size);
long long			ft_atoill(const char *str);
int					ft_isblank(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
size_t				ft_strlen(const char *str);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memcpy(void *dst, const void *src, size_t n);

#endif
