/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:10:07 by mvogel            #+#    #+#             */
/*   Updated: 2023/01/12 16:39:43 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cp(int l_s, const char *s, char *str)
{
	while (l_s)
	{
		*str = *s;
		str++;
		s++;
		l_s--;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l_s1;
	int		l_s2;
	int		i;
	char	*str;

	if (!(s1))
		return (NULL);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	i = l_s1 + l_s2;
	str = malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (NULL);
	str = ft_cp(l_s1, s1, str);
	str = ft_cp(l_s2, s2, str);
	*str = '\0';
	return (str - i);
}
