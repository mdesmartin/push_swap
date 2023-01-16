/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:41:11 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/16 17:57:28 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	t_list	**actions;

	a = malloc(sizeof(t_list *));
	*a = NULL;
	if (!a)
		return (0);
	fill(a, parsing(argc, argv));
	// check_error(argv);
	// normalize_list
	// solver()
	return (0);
}
