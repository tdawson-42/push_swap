/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:21:02 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/19 22:56:28 by tdawson          ###   ########.fr       */
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
		execute(SA, stack, NULL, 1);
	if (order == 2 || order == 5)
		execute(RA, stack, NULL, 1);
	if (order == 0 || order == 4)
		execute(RRA, stack, NULL, 1);
}

int	search_position(t_stack stack, int n)
{
	int		i;
	t_node	*before;
	t_node	*after;

	i = 0;
	before = stack.head->prev;
	after = stack.head;
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

t_b2a	left_rotate(int a_pos, int b_pos)
{
	t_b2a	moves;

	moves.op1 = RR;
	moves.op1_count = ft_min(a_pos, b_pos);
	if (a_pos > b_pos)
		moves.op2 = RA;
	else
		moves.op2 = RB;
	moves.op2_count = ft_abs(a_pos - b_pos);
	moves.total = moves.op1_count + moves.op2_count;
	return (moves);
}

t_b2a	right_rotate(int a_pos, int b_pos)
{
	t_b2a	moves;

	moves.op1 = RRR;
	moves.op1_count = ft_min(a_pos, b_pos);
	if (a_pos > b_pos)
		moves.op2 = RRA;
	else
		moves.op2 = RRB;
	moves.op2_count = ft_abs(a_pos - b_pos);
	moves.total = moves.op1_count + moves.op2_count;
	return (moves);
}

t_b2a	mixed_rotate(int a_pos, int a_len, int b_pos, int b_len)
{
	t_b2a	moves;

	moves.op1 = RA;
	moves.op1_count = a_pos;
	moves.op2 = RB;
	moves.op2_count = b_pos;
	if ((a_len - a_pos) < a_pos)
	{
		moves.op1 = RRA;
		moves.op1_count = a_len - a_pos;
	}
	if ((b_len - b_pos) < b_pos)
	{
		moves.op2 = RRB;
		moves.op2_count = b_len - b_pos;
	}
	moves.total = moves.op1_count + moves.op2_count;
	return (moves);
}

t_b2a	ss(int a_pos, int a_len, int b_pos, int b_len)
{
	t_b2a	l_rot;
	t_b2a	r_rot;
	t_b2a	mix_rot;
	t_b2a	shortest;

	l_rot = left_rotate(a_pos, b_pos);
	r_rot = right_rotate(a_len - a_pos, b_len - b_pos);
	mix_rot = mixed_rotate(a_pos, a_len, b_pos, b_len);
	shortest = l_rot;
	if (r_rot.total < l_rot.total)
		shortest = r_rot;
	if (mix_rot.total < shortest.total)
		shortest = mix_rot;
	return (shortest);
}

t_b2a	shortest_path(t_stack a, t_stack b)
{
	int		b_pos;
	t_node	*node;
	t_b2a	shortest;
	t_b2a	ret;

	b_pos = 0;
	shortest.total = -1;
	node = b.head;
	while (1)
	{	
		ret = ss(search_position(a, node->n), a.size, b_pos, b.size);
		if (shortest.total == -1 || ret.total < shortest.total)
			shortest = ret;
		if (node == b.head->prev)
			break ;
		node = node->next;
		b_pos++;
	}
	return (shortest);
}

void	align_stack(t_stack *stack)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->head;
	while (node->prev->n < node->n)
	{
		node = node->next;
		i++;
	}
	if (i < stack->size - i)
		while (i--)
			execute(RA, stack, NULL, 1);
	else
	{
		i = stack->size - i;
		while (i--)
			execute(RRA, stack, NULL, 1);
	}
}

void	push_swap(int *nums, int count)
{
	t_stack	a;
	t_stack	b;
	t_stack	lis;
	t_b2a	moves;

	a.size = 0;
	b.size = 0;
	array_to_stack(nums, count, &a);
	if (count <= 8)
	{
		while (a.size > 3)
			execute(PB, &a, &b, 1);
		sort3(&a, a.head->n, a.head->next->n, a.head->prev->n);
	}
	else
	{	
		lis = get_lis(nums, count);
		while (a.size != lis.size)
		{
			if (a.head->n != lis.head->n)
				execute(PB, &a, &b, 1);
			else
			{
				execute(RA, &a, NULL, 1);
				lis.head = lis.head->next;
			}
		}
	}
	while (b.size > 0)
	{
		moves = shortest_path(a, b);
		while (moves.op1_count--)
			execute(moves.op1, &a, &b, 1);
		while (moves.op2_count--)
			execute(moves.op2, &a, &b, 1);
		execute(PA, &a, &b, 1);
	}
	align_stack(&a);
}
