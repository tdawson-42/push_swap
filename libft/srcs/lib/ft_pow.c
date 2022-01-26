/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:25:27 by tdawson           #+#    #+#             */
/*   Updated: 2020/01/30 18:25:54 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double base, double exponent)
{
	double		n;

	n = base;
	while (--exponent)
		n *= base;
	return (n);
}
