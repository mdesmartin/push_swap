/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:32:57 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/25 17:07:29 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	normalize(t_list **a)
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
			if (ft_atoi_long(i->content) > ft_atoi_long(j->content))
				index++;
			j = j->next;
		}
		i->index = index;
		nb_arg++;
		i = i->next;
	}
	return (nb_arg);
}

static void	check_duplicate(t_list **a, t_list **b)
{
	t_list	*i;
	t_list	*j;

	i = *a;
	while (i)
	{
		j = *a;
		while (j)
		{
			if (ft_atoi_long(i->content) == ft_atoi_long(j->content) && i != j)
			{
				ft_putstr_fd("Error\n", 2);
				exit_after_sort(a, b);
			}
			j = j->next;
		}
		i = i->next;
	}
	return ;
}

static void	check_error(char *str, t_list **a, t_list **b)
{
	int	i;

	i = 0;
	if (ft_atoi_long(str) < INT_MIN || ft_atoi_long(str) > INT_MAX
		|| ft_strlen(str) > 11)
	{
		free(str);
		ft_putstr_fd("Error\n", 2);
		exit_after_sort(a, b);
	}
	while (str[i])
	{
		if (((str[i] == '-' || str[i] == '+') && !(ft_isdigit(str[i + 1]))
				&& str[i - 1] != ' ') || (!(ft_isdigit(str[i]))
				&& str[i] != '+' && str[i] != '-' && str[i] != ' '))
		{
			free(str);
			ft_putstr_fd("Error\n", 2);
			exit_after_sort(a, b);
		}
		i++;
	}
}

int	parsing(int argc, char **argv, t_list **a, t_list **b)
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
			check_error(tab[i], a, b);
			if (*a == NULL)
				*a = ft_lstnew(tab[i]);
			else
				ft_lstadd_back(a, ft_lstnew(tab[i]));
			i++;
		}
		c++;
		free(tab);
	}
	check_duplicate(a, b);
	return (normalize(a));
}
