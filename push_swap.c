/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:21:02 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/18 20:22:08 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

void	array_to_stack(int *nums, int count, t_stack *stack)
{
	t_node	*node;

	while (--count >= 0)
	{
		node = malloc(sizeof(t_node));
		node->n = nums[count];
		push(stack, node);
	}
}

void	sort3(t_stack *stack, int a, int b, int c)
{
	unsigned int	order;

	order = ((a < b) << 2) + ((b < c) << 1) + (a < c);
	if (order == 0 || order == 3 || order == 5)
	{
		swap(stack);
		write(STDOUT_FILENO, "sa\n", 3);
	}
	if (order == 2 || order == 5)
	{
		rotate(stack, -1);
		write(STDOUT_FILENO, "ra\n", 3);
	}
	if (order == 0 || order == 4)
	{
		rotate(stack, 1);
		write(STDOUT_FILENO, "rra\n", 4);
	}
}

int	search_position(t_stack *stack, int n)
{
	int		i;
	t_node	*before;
	t_node	*after;

	i = 0;
	before = stack->head->prev;
	after = stack->head;
	while (1)
	{
		if (before->n < n && n < after->n)
			return (i);
		if (before->n < n && n > after->n && before->n > after->n)
			return (i);
		if (before->n > n && n < after->n && before->n > after->n)
			return (i);
		before = before->next;
		after = after->next;
		i++;
	}
}

void	push_swap(int *nums, int count)
{
	t_stack	a;
	t_stack	b;

	a.size = 0;
	b.size = 0;
	array_to_stack(nums, count, &a);
	// while (a.size > 3)
	// {
	// 	push(&b, pop(&a));
	// 	write(STDOUT_FILENO, "pb\n", 3);
	// }
	// sort3(&a, a.head->n, a.head->next->n, a.head->prev->n);
	int to_push = a.size / 2;
	for (int i = 0; i < to_push; i++)
		push(&b, pop(&a));
	print_stack('A', a);
	print_stack('B', b);

	t_node *nd = b.head;
	for (int i = 0; i < b.size; i++)
	{
		printf("num %d, b_pos %d, a_pos %d\n", nd->n, i, search_position(&a, nd->n));
		nd = nd->next;
	}
	return ;
}
