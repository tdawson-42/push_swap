/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:29:22 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 18:39:52 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

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
