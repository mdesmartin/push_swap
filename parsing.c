/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:32:57 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/20 18:02:41 by mvogel           ###   ########lyon.fr   */
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

void	check_duplicate(t_list **a)
{
	t_list	*i;
	t_list	*j;

	i = *a;
	while (i)
	{
		j = *a;
		while (j)
		{
			if (ft_atoi(i->content) == ft_atoi(j->content) && i != j)
				return (ft_putstr_fd("Error\n", 2), exit(0));
			j = j->next;
		}
		i = i->next;
	}
	return ;
}

void	check_error(char *tab)
{
	int	i;

	i = 0;
	ft_printf("%d\n",ft_atoi(tab));
	if (ft_atoi(tab) < INT_MIN || ft_atoi(tab) > INT_MAX || ft_strlen(tab) > 11)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
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
	check_duplicate(a);
	return (normalize(a));
}
