/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:29:22 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/17 18:48:46 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "push_swap.h"

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
	len = strlen(s);
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

int	main(int argc, char **argv)
{
	int			i;
	int			*nums;

	if (argc > 1)
	{
		if (!check_input(argc, argv))
			exit_error();
		if (argc == 2)
			return (0);
		nums = malloc((argc - 1) * sizeof(int));
		i = 0;
		while (++i < argc)
			nums[i - 1] = ft_atoi(argv[i]);
		if (!check_dupes(nums, argc - 1))
			exit_error();
		if (is_sorted(nums, argc - 1))
			return (0);
		if (argc == 3 && nums[0] > nums[1])
		{
			write(STDOUT_FILENO, "sa\n", 3);
			return (0);
		}
		push_swap(nums, argc - 1);
	}
	return (0);
}
