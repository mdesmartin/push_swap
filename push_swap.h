/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:32:21 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/25 17:04:57 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

int		parsing(int argc, char **argv, t_list **a, t_list **b);
void	sorting(t_list **a, t_list **b, int nb_arg);
void	rotate(t_list **stack, char *instruct);
void	r_rotate(t_list **stack, char *instruct);
void	swap(t_list **stack, char *instruct);
void	push(t_list **from, t_list **to, char *instruct);
void	exit_after_sort(t_list **a, t_list **b);

#endif