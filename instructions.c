/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:11:46 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 21:42:34 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "libft.h"

char	**get_operations(void)
{
	static char	*op[] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"
	};

	return (op);
}

void	execute(t_operation op, t_stack *a, t_stack *b, int print)
{
	int		dir;

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
		ft_putendl(get_operations()[op]);
}
