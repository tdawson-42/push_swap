/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:26:52 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 19:00:17 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

# define INT_MAX_S "2147483647"
# define INT_MIN_S "-2147483648"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	int_overflow(char *s)
{
	int	sign;
	int	len;

	sign = (*s == '-' || *s == '+');
	len = ft_strlen(s);
	if (len > 10 + sign)
		return (1);
	if (*s == '-')
		return (len == 11 && ft_strcmp(INT_MIN_S, s) < 0);
	else
		return (len == 10 + sign && ft_strcmp(INT_MAX_S, s + sign) < 0);
}

int	check_dupes(int *nums, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[i] == nums[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!is_numeric(argv[i]))
			break ;
		if (int_overflow(argv[i]))
			break ;
	}
	return (i == argc);
}

int	is_valid_instruction(char *inst)
{	
	int		i;
	char	**ops;

	ops = get_operations();
	i = 0;
	while (i < OP_COUNT)
		if (ft_strcmp(inst, ops[i++]) == 0)
			return (0);
	return (1);
}
