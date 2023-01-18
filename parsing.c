/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:32:57 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/18 17:57:15 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	rotate(t_list **a)
// {
// 	t_list	*first;
// 	t_list	*second;

// 	first = *a;
// 	second = (*a)->next;
// 	ft_lstadd_back(&a, first);
// 	*a = second;
// 	first->next = NULL;
// }

// void	swap(t_list **from, t_list **to)
// {
	
// }

// void	push(t_list **from, t_list **to)
// {
// 	if (!from || !to)
// 		return ;
// 	ft_lstadd_front(to, *from);
// }

// int	is_sorted(t_list **a)
// {
// 	return 0 si pas sorted
// }

// void	radix_sort(t_list **a, t_list **b, int nb_arg)
// {
// 	int	i;
// 	int	nb_b;

// 	i = 1;
// 	nb_b = 0;
// 	while (!(is_sorted(a)))
// 	{
// 		while (i < nb_arg)
// 		{
// 			if ((*a->index) >> i & 1)
// 				rotate_a(a); // keep 1
// 			else
// 			{
// 				push_b(a, b); // b keep 0
// 				nb_b++;
// 			}
// 			i++;
// 		}
// 		while (nb_b)
// 		{
// 			push_a(a, b);
// 			nb_b--;
// 		}
// 	}
// }

// void	normalize(t_list **a)
// {
// 	t_list	*i;
// 	t_list	*j;
// 	int		index;

// 	i = *a;
// 	while (i)
// 	{
// 		index = 0;
// 		j = *a;
// 		while (j)
// 		{
// 			if (ft_atoi(i->content) > ft_atoi(j->content))
// 				index++;
// 			j = j->next;
// 		}
// 		i->index = index;
// 		i = i->next;
// 	}
// }

void	check_error(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (((tab[i] == '+' || tab[i] == '-')
				&& (tab[i + 1] == '+' || tab[i + 1] == '-'))
			|| (!(ft_isdigit(tab[i])) && tab[i] != '+'
				&& tab[i] != '-' && tab[i] != ' '))
			return (ft_putstr_fd("Error\n", 2), exit(0));
		i++;
	}
}

void	parsing(int argc, char **argv, t_list **a)
{
	char	**tab;
	int		i;
	int		c;

	c = 1;
	tab = NULL;
	while (c < argc)
	{
		i = 0;
		tab = ft_split(argv[c], ' ');
		while (tab[i])
		{
			check_error(tab[i]);
			if (*a == NULL)
				*a = ft_lstnew(tab[i]);
			else
				ft_lstadd_back(a, ft_lstnew(tab[i]));
			i++;
		}
		c++;
	}
	// radix_sort(a, b, nb_arg);
}
