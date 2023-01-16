/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:32:57 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/16 17:28:25 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parsing(int argc, char **argv)
{
	char	*str;
	char	**strr;
	int		i;
	t_list chain;

	i = 1;
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	error_numb(str);
	strr = ft_split(str, ' ');
	error_dup(strr);
	return (strr);
}

void	error_numb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]))
			&& str[i] != '+' && str[i] != '-' && str[i] != ' ')
			return (ft_putstr_fd("Error\n", 2));
		i++;
	}
}

void	error_dup(char **strr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strr[i])
	{
		while (strr[i][j])
		{
			if ((strr[i][j] == '+' || strr[i][j] == '-')
				&& (strr[i][j + 1] == '+' || strr[i][j + 1] == '-'))
				return (ft_putstr_fd("Error\n", 2));
			j++;
		}
		i++;
	}
}
