/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:32:57 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/27 13:39:43 by mvogel           ###   ########lyon.fr   */
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

void	create_chain(t_list **a, t_list **b, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (*a == NULL)
		{
			*a = ft_lstnew(tab[i]);
			if (!*a)
				return (free_tab(tab), display_error(a, b));
		}
		else
		{
			ft_lstadd_back(a, ft_lstnew(tab[i]));
		}
		i++;
	}
	free(tab);//
	return ;
}

char	*join_to_str(char *str, char *arg, t_list **a, t_list **b)
{
	char	*dst;
	int		digit;
	int		i;

	i = 0;
	digit = 0;
	while (arg[i] != '\0')
	{
		digit += ft_isdigit(arg[i]);
		i++;
	}
	if (arg[0] == '\0' || digit == 0)
	{
		free(str);
		display_error(a, b);
	}
	dst = NULL;
	dst = ft_strjoin(str, arg);
	free (str);
	check_malloc(dst, a, b);
	str = NULL;
	str = ft_strjoin(dst, " ");
	free(dst);
	check_malloc(str, a, b);
	return (str);
}

char	**create_tab(int argc, char **argv, t_list **a, t_list **b)
{
	char	*str;
	char	**tab;
	int		i;

	str = malloc(sizeof(char));
	check_malloc(str, a, b);
	str[0] = '\0';
	tab = NULL;
	i = 1;
	while (i < argc)
	{
		str = join_to_str(str, argv[i], a, b);
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
	create_chain(a, b, tab);
	check_arg(a, b);
	check_duplicate(a, b);
	nb_arg = normalize(a);
	return (nb_arg);
}
