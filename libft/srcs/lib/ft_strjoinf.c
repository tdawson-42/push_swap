/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:42:43 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 19:43:49 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char const *s1, char const *s2, int n)
{
	char	*join;

	join = ft_strjoin(s1, s2);
	if (!join)
		return (NULL);
	if (n == 1)
		ft_strdel((char **)&s1);
	else if (n == 2)
		ft_strdel((char **)&s2);
	else
	{
		ft_strdel((char **)&s1);
		ft_strdel((char **)&s2);
	}
	return (join);
}
