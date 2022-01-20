/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:39:55 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 22:42:25 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_node
{
	int				n;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}	t_stack;

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_operation;

typedef struct s_b2a
{
	t_operation	op1;
	t_operation	op2;
	int			op1_count;
	int			op2_count;
	int			total;
}	t_b2a;

//stack operations
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack, int n);

//printing DELETE
void	print_stack(char id, t_stack stack);
void	print_array(int *nums, int count);

//Input validation
int		check_input(int argc, char **argv);
int		check_dupes(int *nums, int count);
int		is_valid_instruction(char *inst);
void	exit_error(void);

void	push_swap(int *nums, int count);
void	execute(t_operation op, t_stack *a, t_stack *b, int print);
char	**get_operations(void);
t_stack	get_lis(int *nums, int size);
int		is_sorted(int *nums, int count);
int		is_stack_sorted(t_stack stack);
int		is_numeric(const char *s);
void	array_to_stack(int *nums, int count, t_stack *stack);

#endif