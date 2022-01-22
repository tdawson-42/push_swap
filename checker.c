/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:18:22 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/22 19:32:18 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static int	get_operation(char *input)
{	
	int		i;
	char	**ops;

	ops = operation_strings();
	i = 0;
	while (i < OP_COUNT)
	{
		if (ft_strcmp(input, ops[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static void	checker(int *nums, int size)
{
	t_stack		a;
	t_stack		b;
	t_operation	op;
	char		*input;

	a.size = 0;
	b.size = 0;
	array_to_stack(nums, size, &a);
	while (get_next_line(0, &input))
	{
		op = get_operation(input);
		free(input);
		if ((signed)op == -1)
			exit_program(ERROR, nums);
		execute(op, &a, &b, 0);
	}
	if (a.size == size && b.size == 0 && is_stack_sorted(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	while (a.size > 0)
		free(pop(&a));
	while (b.size > 0)
		free(pop(&b));
}

int	main(int argc, char **argv)
{
	int			*nums;

	if (argc < 2)
		return (0);
	if (!check_input(argc, argv))
		exit_program(ERROR, NULL);
	nums = args_to_int_arr(argv + 1, argc - 1);
	if (!check_duplicates(nums, argc - 1))
		exit_program(ERROR, nums);
	checker(nums, argc - 1);
	free(nums);
	return (0);
}
