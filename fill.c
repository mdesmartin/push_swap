/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:52:05 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/17 13:03:58 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill(t_list **a, char **strr)
{
	int	i;

	i = 0;
	while (strr[i])
	{
		if (*a == NULL)
			*a = ft_lstnew(strr[i]);
		else
			ft_lstadd_back(a, ft_lstnew(strr[i]));
		i++;
	}
}
