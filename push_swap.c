/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:29:22 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/22 18:37:02 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

void	sort_b_to_a(t_stack *a, t_stack *b)
{
	t_b2a	moves;

	while (b->size > 0)
	{
		moves = shortest_path(*a, *b);
		while (moves.op1_count--)
			execute(moves.op1, a, b, 1);
		while (moves.op2_count--)
			execute(moves.op2, a, b, 1);
		execute(PA, a, b, 1);
	}
}

void	sort_large_stack(t_stack *a, t_stack *b, int *nums, int size)
{
	t_stack		lis;
	long long	mean;

	mean = ft_sum(nums, size) / size;
	lis = longest_incr_subseq(nums, size);
	while (a->size != lis.size)
	{
		if (a->head->n != lis.head->n)
		{
			execute(PB, a, b, 1);
			if (b->head->n < mean)
				execute(RB, NULL, b, 1);
		}
		else
		{
			execute(RA, a, NULL, 1);
			lis.head = lis.head->next;
		}
	}
	while (lis.size > 0)
		free(pop(&lis));
	sort_b_to_a(a, b);
}

void	sort_3(t_stack *stack, int a, int b, int c)
{
	unsigned int	order;

	order = ((a < b) << 2) + ((b < c) << 1) + (a < c);
	if (order == 0 || order == 3 || order == 5)
		execute(SA, stack, NULL, 1);
	if (order == 2 || order == 5)
		execute(RA, stack, NULL, 1);
	if (order == 0 || order == 4)
		execute(RRA, stack, NULL, 1);
}

void	push_swap(int *nums, int size)
{
	t_stack	a;
	t_stack	b;

	a.size = 0;
	b.size = 0;
	array_to_stack(nums, size, &a);
	if (size <= 8)
	{
		while (a.size > 3)
			execute(PB, &a, &b, 1);
		sort_3(&a, a.head->n, a.head->next->n, a.head->prev->n);
		sort_b_to_a(&a, &b);
	}
	else
		sort_large_stack(&a, &b, nums, size);
	align_stack(&a);
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
	if (argc == 2)
		return (0);
	nums = args_to_int_arr(argv + 1, argc - 1);
	if (!check_duplicates(nums, argc - 1))
		exit_program(ERROR, nums);
	if (is_sorted(nums, argc - 1))
		exit_program(NO_ERROR, nums);
	if (argc == 3)
		ft_putstr("sa\n");
	else
		push_swap(nums, argc - 1);
	free(nums);
	return (0);
}
