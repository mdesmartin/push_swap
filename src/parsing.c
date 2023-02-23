/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:32:57 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/23 13:27:20 by mvogel           ###   ########lyon.fr   */
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

static void	check_arg(t_list **a, t_list **b)
{
	t_list	*l_cp;
	char	*str;
	int		i;

	l_cp = *a;
	while (l_cp)
	{
		str = l_cp->content;
		if (ft_atoi_long(str) < INT_MIN || ft_atoi_long(str) > INT_MAX
			|| ft_strlen(str) > 11)
			return (display_error(a, b));
		while (str[i])
		{
			if (((str[i] == '-' || str[i] == '+') && !(ft_isdigit(str[i + 1])))
				|| (!(ft_isdigit(str[i])) && str[i] != '+' && str[i] != '-'))
				return (display_error(a, b));
			i++;
		}
		l_cp = l_cp->next;
	}
	return ;
}

void	create_chain(t_list **a, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (*a == NULL)
			*a = ft_lstnew(tab[i]);
		else
			ft_lstadd_back(a, ft_lstnew(tab[i]));
		i++;
	}
	free (tab);
	return ;
}

char	**create_tab(int argc, char **argv, t_list **a, t_list **b)
{
	char	*str;
	char	**tab;
	int		i;

	str = NULL;
	tab = NULL;
	i = 1;
	while (i < argc)
	{
		str = add_to_stash(str, argv[i]);
		if (!str)
			display_error(a, b);
		// str = ft_strjoin(str, " ");
		// if (!str)
		// 	display_error(a, b);
		i++;
	}
	tab = ft_split(str, ' ');
	free (str);
	if (!tab)
		display_error(a, b);
	return (tab);
}

int	parsing(int argc, char **argv, t_list **a, t_list **b)
{
	char	**tab;
	int		nb_arg;

	tab = create_tab(argc, argv, a, b);
	create_chain(a, tab);
	check_arg(a, b);
	check_duplicate(a, b);
	nb_arg = normalize(a);
	return (nb_arg);
}
