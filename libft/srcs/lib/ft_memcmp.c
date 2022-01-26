/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:49:04 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:19:37 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ptr1[i] == ptr2[i] && i < n - 1)
		i++;
	return (ptr1[i] - ptr2[i]);
}
