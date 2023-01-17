/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:32:57 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/17 17:15:32 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// char	*normalize(char **tab, char *str)
// {
// 	int	value;
// 	int	i;

// 	i = 0;
// 	value = 0;
// 	while (tab[i])
// 	{
// 		if (str > tab[i])
// 			value++;
// 		i++;
// 	}
// 	return (ft_itoa(value));
// }

char	*index(char	*tab)
{
	int	index;
	
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
}
