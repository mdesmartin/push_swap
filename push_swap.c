/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:23:21 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/25 17:04:22 by mvogel           ###   ########lyon.fr   */
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
}

void	exit_after_sort(t_list **a, t_list **b)
{
	ft_lstclear(a, free_del);
	ft_lstclear(b, del);
	free(a);
	free(b);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	a = malloc(sizeof(t_list *));
	if (!a)
		return (0);
	b = malloc(sizeof(t_list *));
	if (!b)
		return (free(a), 0);
	*a = NULL;
	*b = NULL;
	sorting(a, b, parsing(argc, argv, a, b));
	exit_after_sort(a, b);
}
