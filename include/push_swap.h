/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:32:21 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/21 14:14:46 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

int		parsing(int argc, char **argv, t_list **a, t_list **b);
void	sorting(t_list **a, t_list **b, int nb_arg);
void	rotate(t_list **stack, char *instruct);
void	r_rotate(t_list **stack, char *instruct);
void	swap(t_list **stack, char *instruct);
void	push(t_list **from, t_list **to, char *instruct);
void	display_error(t_list **a, t_list **b, int fre);
void	free_n_exit(t_list **a, t_list **b, int fre);
void	*free_tab(char **tab);

#endif