/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:44:07 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:41:18 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isstrspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	ft_spaceatbegin(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (ft_isstrspace(s[i]) && s[i])
		i++;
	return (i);
}

static int	ft_spaceatend(const char *s, int start)
{
	int	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	while (i > start && ft_isstrspace(s[i - 1]))
		i--;
	return (i);
}

char	*ft_strtrim(const char *s)
{
	int		start;
	int		end;
	char	*trim;

	start = ft_spaceatbegin(s);
	end = ft_spaceatend(s, start);
	trim = ft_strsub(s, start, end - start);
	return (trim);
}
