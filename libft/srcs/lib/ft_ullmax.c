/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:26:17 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:43:05 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_ullmax(unsigned long long a, unsigned long long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
