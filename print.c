/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:44:46 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/22 19:38:02 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	print_array(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("%d ", nums[i++]);
	putc('\n', stdout);
}

void	print_stack(char id, t_stack stack)
{
	t_node	*ptr;

	printf("%c[%d]:", id, stack.size);
	if (stack.size > 0)
	{	
		ptr = stack.head;
		while (1)
		{
			printf(" %d", ptr->n);
			if (ptr == stack.head->prev)
				break ;
			ptr = ptr->next;
		}
	}
	putc('\n', stdout);
}
