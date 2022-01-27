/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:39:55 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/27 17:32:48 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# define ERROR 1
# define NO_ERROR 0

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
void	rotate(t_stack *stack, int dir);
void	execute(t_operation op, t_stack *a, t_stack *b, int print);

//printing DELETE
void	print_stack(char id, t_stack stack);
void	print_array(int *nums, int size);

//argument validation
int		validate_args(int argc, char **argv);
int		find_duplicates(int *nums, int size);

//algorithms for sorting
t_stack	longest_incr_subseq(int *nums, int size);
t_b2a	minimum_moves(t_stack a, t_stack b);

//stack utility functions
int		is_stack_sorted(t_stack stack);
void	align_stack(t_stack *stack);
void	array_to_stack(int *arr, int size, t_stack *stack);

//other utility functions
void	exit_program(int error, int *nums);
char	**operation_strings(void);
int		is_sorted(int *arr, int size);
int		*args_to_int_arr(char **args, int size);

#endif