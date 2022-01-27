/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:34:29 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/27 18:12:09 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	array_to_stack(int *arr, int size, t_stack *stack)
{
	t_node	*node;

	while (--size >= 0)
	{
		node = malloc(sizeof(t_node));
		node->n = arr[size];
		push(stack, node);
	}
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

int	is_stack_sorted(t_stack stack)
{
	t_node	*node;

	node = stack.head;
	while (node != stack.head->prev)
	{
		if (node->n > node->next->n)
			return (0);
		node = node->next;
	}
	return (1);
}
