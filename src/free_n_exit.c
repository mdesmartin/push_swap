/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:52:58 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/21 14:14:58 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_del(void *content)
{
	free(content);
	content = NULL;
}

static void	del(void *content)
{
	content = NULL;
	(void) content;
}

void	free_n_exit(t_list **a, t_list **b, int fre)
{
	if (fre == 0)
		ft_lstclear(a, del);
	else
		ft_lstclear(a, free_del);
	ft_lstclear(b, del);
	free(a);
	free(b);
	exit(0);
}

void	display_error(t_list **a, t_list **b, int fre)
{
	ft_putstr_fd("Error\n", 2);
	free_n_exit(a, b, fre);
}

void	*free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}
