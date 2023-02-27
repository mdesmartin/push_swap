/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:58:07 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/27 12:45:22 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	int		i;
	int		len;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	i = 0;
	len = count * size;
	str = malloc(sizeof(char) * len);
	if (!(str))
		return (0);
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
