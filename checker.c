/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:18:22 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 18:29:53 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int			i;
	int			*nums;

	if (argc < 2)
		return (0);
	if (!check_input(argc, argv))
		exit_error();
	if (argc == 2)
		return (0);
	nums = malloc((argc - 1) * sizeof(int));
	i = 0;
	while (++i < argc)
		nums[i - 1] = ft_atoi(argv[i]);
	if (!check_dupes(nums, argc - 1))
	{
		free(nums);
		exit_error();
	}
	return (0);
}
