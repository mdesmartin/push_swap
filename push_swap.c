/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:23:21 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/14 17:51:10 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_list *));
	if (!a)
		return (ft_putstr_fd("Error\n", 2), exit(0), 0);
	b = malloc(sizeof(t_list *));
	if (!b)
		return (free(a), ft_putstr_fd("Error\n", 2), exit(0), 0);
	*a = NULL;
	*b = NULL;
	sorting(a, b, parsing(argc, argv, a, b));
	free_n_exit(a, b);
}
