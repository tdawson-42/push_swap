/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:39:55 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/18 19:29:14 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX_S "2147483647"
# define INT_MIN_S "-2147483648"

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
	RRR
}	t_operation;

// typedef struct s_move
// {
// 	t_moves			move;
// 	int				repeat;
// 	struct s_move	*next;
// }	t_move;

//library functions
int		ft_atoi(const char *str);
int		is_numeric(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		is_sorted(int *nums, int count);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

//stack operations
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack, int n);

//printing DELETE
void	print_stack(char id, t_stack stack);
void	print_array(int *nums, int count);

void	push_swap(int *nums, int count);

#endif