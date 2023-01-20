
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
				rotate(a, "ra\n"); // keep 1
			else
				push(a, b, "pb\n"); // b keep 0
			i++;
		}
		while (*b)
			push(b, a, "pa\n");
		j++;
	}
}

void	sort(t_list **a, t_list **b, int nb_arg)
{
	if (nb_arg > 1)
	{
		ft_printf("-- plus de cinq --\n");
		radix(a, b, nb_arg);
	}
	// else if (nb_arg == 3)
	// 	three_arg(a, b);
	else if (nb_arg == 2 && !is_sorted(a))
	{
		ft_printf("-- deux --\n");
		rotate(a, "ra\n");
	}
	else
		return ;
}

