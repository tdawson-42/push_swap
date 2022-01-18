/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:07:16 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/18 19:10:22 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //NULL
#include "push_swap.h"

void	swap(t_stack *stack)
{
	int		tmp;
	t_node	*head;

	head = stack->head;
	tmp = head->n;
	head->n = head->next->n;
	head->next->n = tmp;
}

void	rotate(t_stack *stack, int n)
{
	if (n > 0)
		while (n-- != 0)
			stack->head = stack->head->prev;
	else
		while (n++ != 0)
			stack->head = stack->head->next;
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
