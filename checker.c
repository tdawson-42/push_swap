/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:18:22 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 23:05:06 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	checker(int *nums, int size)
{
	t_stack		a;
	t_stack		b;
	t_operation	op;
	char		*line;

	a.size = 0;
	b.size = 0;
	array_to_stack(nums, size, &a);
	while (get_next_line(0, &line))
	{
		op = is_valid_instruction(line);
		if ((signed)op == -1)
			exit_error();
		execute(op, &a, &b, 0);
	}
	if (b.size == 0 && is_stack_sorted(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int argc, char **argv)
{
	int			i;
	int			*nums;

	if (argc < 2)
		return (0);
	if (!check_input(argc, argv))
		exit_error();
	nums = malloc((argc - 1) * sizeof(int));
	i = 0;
	while (++i < argc)
		nums[i - 1] = ft_atoi(argv[i]);
	if (!check_dupes(nums, argc - 1))
	{
		free(nums);
		exit_error();
	}
	checker(nums, argc - 1);
	return (0);
}
