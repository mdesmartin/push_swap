/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:23:14 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/23 17:53:37 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, char *instruct)
{
	t_list	*first;
	t_list	*second;

	if (!stack)
		return ;
	first = *stack;
	second = (*stack)->next;
	ft_lstadd_back(stack, first);
	*stack = second;
	first->next = NULL;
	ft_putstr_fd(instruct, 1);
}

void	r_rotate(t_list **stack, char *instruct);

void	push(t_list **from, t_list **to, char *instruct)
{
	t_list	*first_from;
	t_list	*second_from;
	t_list	*first_to;

	if (!from || !to)
		return ;
	first_from = *from;
	second_from = (*from)->next;
	first_to = *to;
	ft_lstadd_front(to, first_from);
	*from = second_from;
	*to = first_from;
	first_from->next = first_to;
	ft_putstr_fd(instruct, 1);
}

int	is_sorted(t_list **a)
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

void	radix(t_list **a, t_list **b, int nb_arg)
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
				rotate(a, "ra\n"); // a keep 1
			else
				push(a, b, "pb\n"); // b keep 0
			i++;
		}
		while (*b)
			push(b, a, "pa\n");
		j++;
	}
}

//find the smaller index and locate it in the half
//then put it in b by ra or rra
//do the same for every index exept the three last
//sort the three lasts and then push a

void	small_sort(t_list **a, t_list **b, int nb_arg);
{
	half_sorting(a, nb_arg, 0);
	
}

int	half_sorting(t_list **a, t_list **b, int nb_arg, int index)
{
	t_list	*i;
	t_list	*j;
	int		x;

	i = *a;
	x = 0;
	if (index < nb_arg - 3)
	{
		j = *a;
		while (i->index != index)
		{
			x++;
			i = i->next;
		}
		if (x < (nb_arg / 2))
			while (j->index != index)
				rotate(a, "ra");
		else
			while (j->index != index)
				r_rotate(a, "rra");
		push(a, b, "pb");
	}
	else
		return (0);
	return (half_sorting(a, b, nb_arg, index + 1));
}

void	sorting(t_list **a, t_list **b, int nb_arg)
{
	if (nb_arg < 25)
		small_sort(a, b, nb_arg);
	else
		radix(a, b, nb_arg);
}
