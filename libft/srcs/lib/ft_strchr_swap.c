/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:47 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:35:53 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strchr_swap(char *s, size_t i, size_t j)
{
	char	tmp;

	if (!s || !(*s) || i == j)
		return ;
	if (j > ft_strlen(s) - 1 || i > ft_strlen(s) - 1)
		return ;
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}
