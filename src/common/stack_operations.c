/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:07:16 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/27 19:28:28 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap(t_stack *stack)
{
	int		tmp;
	t_node	*head;

	if (stack && stack->size >= 2)
	{
		head = stack->head;
		tmp = head->n;
		head->n = head->next->n;
		head->next->n = tmp;
	}
}

void	rotate(t_stack *stack, int dir)
{
	if (stack && stack->size >= 2)
	{
		if (dir > 0)
			stack->head = stack->head->prev;
		else
			stack->head = stack->head->next;
	}
}

void	push(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	stack->size++;
	if (stack->size == 1)
	{
		stack->head = node;
		node->next = node;
		node->prev = node;
		return ;
	}
	node->next = stack->head;
	node->prev = stack->head->prev;
	stack->head->prev->next = node;
	stack->head->prev = node;
	stack->head = node;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 1)
		return (NULL);
	node = stack->head;
	stack->size--;
	if (stack->size == 0)
	{
		stack->head = NULL;
		return (node);
	}
	stack->head = node->next;
	node->prev->next = stack->head;
	node->next->prev = node->prev;
	return (node);
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
		ft_putendl(operation_strings()[op]);
}
