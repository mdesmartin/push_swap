/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:37:03 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/25 17:05:07 by mvogel           ###   ########lyon.fr   */
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

void	r_rotate(t_list **stack, char *instruct)
{
	t_list	*first;
	t_list	*second_last;
	t_list	*last;

	if (!stack)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	second_last = *stack;
	while (second_last->next != last)
		second_last = second_last->next;
	ft_lstadd_front(stack, last);
	*stack = last;
	last->next = first;
	second_last->next = NULL;
	ft_putstr_fd(instruct, 1);
}

void	swap(t_list **stack, char *instruct)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	second = (*stack)->next;
	third = ((*stack)->next)->next;
	ft_lstadd_front(stack, second);
	*stack = second;
	second->next = first;
	first->next = third;
	ft_putstr_fd(instruct, 1);
}

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
