/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:23:14 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/07 14:11:31 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list **a)
{
	t_list	*i;
	t_list	*j;

	i = *a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->index > j->index)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

static void	radix(t_list **a, t_list **b, int nb_arg)
{
	int	i;
	int	j;

	j = 0;
	while (!(is_sorted(a)))
	{
		i = 0;
		while (i < nb_arg)
		{
			if (((*a)->index) >> j & 1)
				rotate(a, "ra\n");
			else
				push(a, b, "pb\n");
			i++;
		}
		while (*b)
			push(b, a, "pa\n");
		j++;
	}
}

static int	half_sorting(t_list **a, t_list **b, int nb_arg, int index)
{
	t_list	*i;
	int		x;

	i = *a;
	x = 0;
	if (index < nb_arg - 3)
	{
		while (i->index != index)
		{
			x++;
			i = i->next;
		}
		if (x < (nb_arg / 2))
			while ((*a)->index != index)
				rotate(a, "ra\n");
		else
			while ((*a)->index != index)
				r_rotate(a, "rra\n");
		push(a, b, "pb\n");
	}
	else
		return (0);
	return (half_sorting(a, b, nb_arg, index + 1));
}

static void	small_sort(t_list **a, t_list **b, int nb_arg)
{
	if (nb_arg > 3)
		half_sorting(a, b, nb_arg, 0);
	if ((*a)->next->index > (*a)->index
		&& (*a)->next->index > (*a)->next->next->index)
		r_rotate(a, "rra\n");
	if ((*a)->index > (*a)->next->next->index)
		rotate(a, "ra\n");
	if ((*a)->index > (*a)->next->index
		&& (*a)->index < (*a)->next->next->index)
		swap(a, "sa\n");
	while (*b)
		push(b, a, "pa\n");
}

void	sorting(t_list **a, t_list **b, int nb_arg)
{
	if (nb_arg == 2 && !is_sorted(a))
		rotate(a, "ra\n");
	else if (nb_arg <= 50 && nb_arg > 2 && !is_sorted(a))
		small_sort(a, b, nb_arg);
	else if (nb_arg > 50 && !is_sorted(a))
		radix(a, b, nb_arg);
	else
		return ;
}
