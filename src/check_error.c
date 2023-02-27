/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:04:02 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/27 15:05:44 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_list **a, t_list **b)
{
	t_list	*i;
	t_list	*j;

	i = *a;
	while (i)
	{
		j = *a;
		while (j)
		{
			if (ft_atoi_long(i->content) == ft_atoi_long(j->content) && i != j)
				return (display_error(a, b));
			j = j->next;
		}
		i = i->next;
	}
	return ;
}

void	check_arg(t_list **a, t_list **b)
{
	t_list	*l_cp;
	char	*str;
	int		i;

	l_cp = *a;
	while (l_cp)
	{
		str = l_cp->content;
		if (ft_atoi_long(str) < INT_MIN || ft_atoi_long(str) > INT_MAX
			|| ft_strlen(str) > 11)
			return (display_error(a, b));
		i = 0;
		while (str[i])
		{
			if (((str[i] == '-' || str[i] == '+') && (!(ft_isdigit(str[i + 1])) \
			|| ft_isdigit(str[i -1]))) || (!(ft_isdigit(str[i])) \
			&& str[i] != '+' && str[i] != '-'))
				return (display_error(a, b));
			i++;
		}
		l_cp = l_cp->next;
	}
	return ;
}

void	check_malloc(char *str, t_list **a, t_list **b)
{
	if (!str)
		display_error(a, b);
}
