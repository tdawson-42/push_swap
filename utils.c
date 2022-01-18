/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:54:48 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/17 20:00:41 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	is_numeric(const char *s)
{
	if (*s == '-' || *s == '+')
		if (!ft_isdigit(*++s))
			return (0);
	while (ft_isdigit(*s))
		s++;
	return (*s == 0);
}

int	is_sorted(int *nums, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (nums[i] > nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	n;
	int					sign;

	sign = 1;
	n = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		++str;
	}
	return (n * sign);
}

int ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}