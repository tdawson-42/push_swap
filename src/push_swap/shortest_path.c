/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:21:02 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/22 19:49:18 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "libft.h"

#define LEFT -1
#define RIGHT 1

static int	search_position(t_stack stack, int n)
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

static t_b2a	same_rotate(int a_pos, int b_pos, int dir)
{	
	int		offset;
	t_b2a	moves;

	if (dir == RIGHT)
		offset = 3;
	else
		offset = 0;
	moves.op1 = RR + offset;
	moves.op1_count = ft_min(a_pos, b_pos);
	if (a_pos > b_pos)
		moves.op2 = RA + offset;
	else
		moves.op2 = RB + offset;
	moves.op2_count = ft_abs(a_pos - b_pos);
	moves.total = moves.op1_count + moves.op2_count;
	return (moves);
}

static t_b2a	mixed_rotate(int a_pos, int a_len, int b_pos, int b_len)
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

static t_b2a	ss(int a_pos, int a_len, int b_pos, int b_len)
{
	t_b2a	l_rot;
	t_b2a	r_rot;
	t_b2a	mix_rot;
	t_b2a	shortest;

	l_rot = same_rotate(a_pos, b_pos, LEFT);
	r_rot = same_rotate(a_len - a_pos, b_len - b_pos, RIGHT);
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
