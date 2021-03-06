/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:19:35 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/22 17:56:23 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static t_stack	get_lis_sequence(const int *seq, int *s, int *p, int lis_len)
{
	t_stack	lis;
	t_node	*node;
	int		curr;

	lis.size = 0;
	curr = s[lis_len - 1];
	while (--lis_len >= 0)
	{
		node = malloc(sizeof(t_node));
		node->n = seq[curr];
		curr = p[curr];
		push(&lis, node);
	}
	return (lis);
}

static int	binary_search(const int *seq, int *s, int i, int up)
{
	int	lo;
	int	mid;

	lo = 1;
	while (lo < up)
	{
		mid = (lo + up) / 2;
		if (seq[s[mid]] < seq[i])
			lo = mid + 1;
		else
			up = mid;
	}
	return (lo);
}

static t_stack	lis(const int *seq, int *s, int *p, int size)
{
	int	i;
	int	j;
	int	lis_len;

	s[0] = 0;
	lis_len = 1;
	i = 0;
	while (++i < size)
	{
		if (seq[i] < seq[s[0]])
			s[0] = i;
		else if (seq[i] > seq[s[lis_len - 1]])
		{	
			p[i] = s[lis_len - 1];
			s[lis_len] = i;
			lis_len++;
		}
		else
		{
			j = binary_search(seq, s, i, lis_len);
			s[j] = i;
			p[i] = s[j - 1];
		}
	}
	return (get_lis_sequence(seq, s, p, lis_len));
}

t_stack	longest_incr_subseq(int *nums, int size)
{	
	t_stack		longest;
	int *const	s = malloc(sizeof(int) * size);
	int *const	p = malloc(sizeof(int) * size);

	longest = lis(nums, s, p, size);
	free(s);
	free(p);
	return (longest);
}
