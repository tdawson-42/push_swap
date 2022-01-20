/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:54:48 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 22:42:04 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

int	is_numeric(const char *s)
{
	if (*s == '-' || *s == '+')
		if (!ft_isdigit(*++s))
			return (0);
	while (ft_isdigit(*s))
		s++;
	return (*s == 0);
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

int	is_sorted(int *nums, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (nums[i] > nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
