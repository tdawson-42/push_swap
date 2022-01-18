/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:07:16 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/17 20:11:07 by tdawson          ###   ########.fr       */
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
	{
		while (n-- != 0)
		{
			stack->head = stack->head->prev;
			stack->tail = stack->tail->prev;
		}
	}
	else
	{
		while (n++ != 0)
		{
			stack->head = stack->head->next;
			stack->tail = stack->tail->next;
		}
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
		stack->tail = node;
		node->next = node;
		node->prev = node;
		return ;
	}
	node->prev = stack->tail;
	node->next = stack->head;
	stack->tail->next = node;
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
		stack->tail = NULL;
		return (node);
	}
	stack->head = node->next;
	stack->tail->next = stack->head;
	node->next->prev = stack->tail;
	return (node);
}
