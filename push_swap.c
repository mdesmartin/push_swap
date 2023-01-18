/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:41:11 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/18 18:01:16 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	t_list	*tmp;
	t_list	*actions;

	a = malloc(sizeof(t_list *));
	*a = NULL;
	parsing(argc, argv, a);
	// normalize(a);
	tmp = *a;
	while (tmp)
	{
		ft_printf("value :%s\n", tmp->content);
		ft_printf("index :%d\n", tmp->index);
		ft_printf("current : %p\n", tmp);
		ft_printf("next : %p\n", tmp->next);
		tmp = tmp->next;
	}
// 	while (a)
// 	{
// 		ft_printf("%s", a->content);
// 		a = a->next;
// 	}
// 	return (0);
}
