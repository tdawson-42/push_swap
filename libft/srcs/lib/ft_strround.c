/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strround.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:18:00 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 19:46:48 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*recursive_round(char *s, int i)
{
	if (i > 0 && s[i] >= '5' && s[i] <= ':')
	{
		if (s[i - 1] == '.')
			i--;
		s[i - 1]++;
		if (s[i - 1] == ':')
			recursive_round(s, i - 1);
	}
	return (s);
}

char	*ft_strround(char *s, int i)
{
	int		j;

	j = 0;
	recursive_round(s, i);
	if (s[j] == '.')
		s[j++] = '-';
	if (s[j] == ':')
	{
		s[j] = '1';
		j = ft_strchr_index(s, '.');
		ft_strchr_swap(s, j, j + 1);
		s[i] = '0';
	}
	else
		s[i] = '\0';
	ft_strchr_replace(s, ':', '0');
	return (s);
}
