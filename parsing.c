/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:32:57 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/14 17:52:30 by mvogel           ###   ########lyon.fr   */
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
				return (display_error(a, b));
			j = j->next;
		}
		i = i->next;
	}
	return ;
}

static void	check_error(char *str, t_list **a, t_list **b, char **tab)
{
	int	i;

	i = 0;
	if (ft_atoi_long(str) < INT_MIN || ft_atoi_long(str) > INT_MAX
		|| ft_strlen(str) > 11)
		return (free_tab(tab), display_error(a, b));
	while (str[i])
	{
		if (((str[i] == '-' || str[i] == '+') && !(ft_isdigit(str[i + 1]))
				&& str[i - 1] != ' ') || (!(ft_isdigit(str[i]))
				&& str[i] != '+' && str[i] != '-' && str[i] != ' '))
			return (free_tab(tab), display_error(a, b));
		i++;
	}
	return ;
}

void	error_tab(char **tab, t_list **a, t_list **b)
{
	if (!tab)
		return (display_error(a, b));
	else if (tab[0] == NULL)
		return (free_tab(tab), display_error(a, b));
	else
		return ;
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
		error_tab(tab, a, b);
		while (tab[i])
		{
			check_error(tab[i], a, b, tab);
			if (*a == NULL)
				*a = ft_lstnew(tab[i]);
			else
				ft_lstadd_back(a, ft_lstnew(tab[i]));
			i++;
		}
		c++;
		free(tab);
	}
	return (check_duplicate(a, b), normalize(a));
}
