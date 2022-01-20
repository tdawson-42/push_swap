/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:11:46 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 18:51:00 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

char	**get_operations(void)
{
	static char	*op[] = {
		"sa\n",
		"sb\n",
		"ss\n",
		"pa\n",
		"pb\n",
		"ra\n",
		"rb\n",
		"rr\n",
		"rra\n",
		"rrb\n",
		"rrr\n"
	};

	return (op);
}

void	execute(t_operation op, t_stack *a, t_stack *b, int print)
{
	int		dir;
	char	*op_string;

	if (op == SA)
		swap(a);
	else if (op == SB)
		swap(b);
	else if (op == PA)
		push(a, pop(b));
	else if (op == PB)
		push(b, pop(a));
	else
	{
		dir = -1 + 2 * (op == RRA || op == RRB || op == RRR);
		if (op == RA || op == RRA || op == RR || op == RRR)
			rotate(a, dir);
		if (op == RB || op == RRB || op == RR || op == RRR)
			rotate(b, dir);
	}
	if (print)
	{
		op_string = get_operations()[op];
		write(1, op_string, ft_strlen(op_string));
	}
}
