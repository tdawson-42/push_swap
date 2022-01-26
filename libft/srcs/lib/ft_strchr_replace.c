/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:59:30 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 21:21:52 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strchr_replace(const char *s, int find, int replace)
{
	char	*ptr;

	ptr = ft_strchr(s, find);
	while (ptr)
	{
		*ptr = replace;
		ptr = ft_strchr(s, find);
	}
}
