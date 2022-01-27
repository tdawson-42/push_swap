/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:21:02 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/27 19:29:56 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		rev;
	t_b2a	moves;

	rev = 3 * (dir == RIGHT);
	moves.op1 = RR + rev;
	moves.op1_count = ft_min(a_pos, b_pos);
	if (a_pos > b_pos)
		moves.op2 = RA + rev;
	else
		moves.op2 = RB + rev;
	moves.op2_count = ft_abs(a_pos - b_pos);
	moves.total = moves.op1_count + moves.op2_count;
	return (moves);
}

static t_b2a	mixed_rotate(int a_pos, int a_len, int b_pos, int b_len)
{
	t_b2a	moves;
	int		a_rpos;
	int		b_rpos;

	a_rpos = a_len - a_pos;
	b_rpos = b_len - b_pos;
	moves.op1 = RA + 3 * (a_rpos < a_pos);
	moves.op1_count = ft_min(a_pos, a_rpos);
	moves.op2 = RB + 3 * (b_rpos < b_pos);
	moves.op2_count = ft_min(b_pos, b_rpos);
	moves.total = moves.op1_count + moves.op2_count;
	return (moves);
}

static t_b2a	min_moves_curr_pos(int a_pos, int a_len, int b_pos, int b_len)
{
	t_b2a	min;
	t_b2a	tmp;

	min = same_rotate(a_pos, b_pos, LEFT);
	tmp = same_rotate(a_len - a_pos, b_len - b_pos, RIGHT);
	if (tmp.total < min.total)
		min = tmp;
	tmp = mixed_rotate(a_pos, a_len, b_pos, b_len);
	if (tmp.total < min.total)
		min = tmp;
	return (min);
}

t_b2a	minimum_moves(t_stack a, t_stack b)
{
	int		b_pos;
	int		a_pos;
	t_node	*node;
	t_b2a	min_moves;
	t_b2a	tmp;

	b_pos = 0;
	min_moves.total = -1;
	node = b.head;
	while (1)
	{	
		a_pos = search_position(a, node->n);
		tmp = min_moves_curr_pos(a_pos, a.size, b_pos, b.size);
		if (min_moves.total == -1 || tmp.total < min_moves.total)
			min_moves = tmp;
		if (node == b.head->prev)
			break ;
		node = node->next;
		b_pos++;
	}
	return (min_moves);
}
