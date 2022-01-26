/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:55:18 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:19:12 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
