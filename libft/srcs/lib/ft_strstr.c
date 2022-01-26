/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:12:12 by tdawson           #+#    #+#             */
/*   Updated: 2019/10/21 17:49:53 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;

	i = 0;
	if (!to_find[i])
		return ((char *)str);
	while (str[i])
	{
		while (str[i] && str[i] == to_find[i])
			i++;
		if (to_find[i] == '\0')
			return ((char *)str);
		if (str[i] != to_find[i])
			i = 0;
		str = str + 1;
	}
	return (0);
}
