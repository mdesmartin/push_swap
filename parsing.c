/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:32:57 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/19 16:48:46 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	normalize(t_list **a)
{
	t_list	*i;
	t_list	*j;
	int		nb_arg;
	int		index;

	nb_arg = 0;
	i = *a;
	while (i)
	{
		index = 0;
		j = *a;
		while (j)
		{
			if (ft_atoi(i->content) > ft_atoi(j->content))
				index++;
			j = j->next;
		}
		i->index = index;
		nb_arg++;
		i = i->next;
	}
	return (nb_arg);
}

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

int	parsing(int argc, char **argv, t_list **a)
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
	return (normalize(a));
}
