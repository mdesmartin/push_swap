/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:32:21 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/20 16:47:48 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# include <limits.h>
# include <stdio.h>
// A SUPPRIMER WEEEEEEEEEEEEEEEEESHHHHHHHHHHHH

int		parsing(int argc, char **argv, t_list **a);
void	sort(t_list **a, t_list **b, int nb_arg);

#endif