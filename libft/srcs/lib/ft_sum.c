/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:59:24 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/21 23:02:52 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_sum(int *nums, int size)
{
	int				i;
	long long int	sum;

	i = 0;
	sum = 0;
	while (i < size)
		sum += nums[i++];
	return (sum);
}
