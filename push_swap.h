/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:32:21 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/19 16:54:30 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# include <stdio.h>

int		parsing(int argc, char **argv, t_list **a);
void	check_error(char *tab);
int		normalize(t_list **stack);
void	sort(t_list **a, t_list **b, int nb_arg);

#endif