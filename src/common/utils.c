/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:54:48 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/22 20:43:49 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "libft.h"

int	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*args_to_int_arr(char **args, int size)
{
	int	i;
	int	*arr;

	i = -1;
	arr = malloc((size) * sizeof(int));
	while (++i < size)
		arr[i] = ft_atoi(args[i]);
	return (arr);
}

char	**operation_strings(void)
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

void	exit_program(int error, int *nums)
{
	if (nums)
		free(nums);
	if (error)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
