/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:26:52 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/26 23:35:24 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	overflows_int(char *s)
{
	int					sign;
	int					len;
	static const char	*int_max_str = "2147483647";
	static const char	*int_min_str = "-2147483648";

	sign = (*s == '-' || *s == '+');
	len = ft_strlen(s);
	if (len > 10 + sign)
		return (1);
	if (*s == '-')
		return (len == 11 && ft_strcmp(int_min_str, s) < 0);
	else
		return (len == 10 + sign && ft_strcmp(int_max_str, s + sign) < 0);
}

int	find_duplicates(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_args(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_str_is_numeric(argv[i]))
			return (0);
		if (overflows_int(argv[i]))
			return (0);
	}
	return (1);
}
