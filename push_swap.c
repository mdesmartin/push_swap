/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:23:21 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/20 13:09:05 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	t_list	*tmp;
	int		nb_arg;
	// t_list	*actions;

	a = malloc(sizeof(t_list *));
	if (!a)
		return (0);
	b = malloc(sizeof(t_list *));
	if (!b)
		return (0);
	*a = NULL;
	*b = NULL;
	nb_arg = parsing(argc, argv, a);
	sort(a, b, nb_arg);
	tmp = *a;
	// while (tmp)
	// {
	// 	ft_printf("value :%s\n", tmp->content);
	// 	ft_printf("index :%d\n", tmp->index);
	// 	ft_printf("current : %p\n", tmp);
	// 	printf("next : %p\n", tmp->next);
	// 	tmp = tmp->next;
	// }
}
