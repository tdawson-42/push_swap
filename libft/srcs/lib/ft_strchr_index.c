/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:58:16 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:35:18 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_index(const char *str, int c)
{
	char	*ptr;

	ptr = ft_strchr(str, c);
	if (!ptr)
		return (-1);
	return ((int)(ptr - str));
}
