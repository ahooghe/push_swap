/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:27:24 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 13:32:37 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "../libstack/include/stack.h"
#include "../libft/include/libft.h"
#include "../include/general.h"

bool	validate_int(char *elem)
{
	bool			is_int;
	unsigned int	i;
	unsigned int	cm;

	i = 0;
	cm = 0;
	is_int = true;
	while (elem[i] && is_int)
	{
		if (elem[i] == '-' && cm < 1)
			cm++;
		else if (!ft_isdigit(elem[i]))
			is_int = false;
		i++;
	}
	return (!is_int);
}

void	insert_sorted(int n, int *data, int size)
{
	int	i;

	i = size;
	while (--i >= 0 && data[i] > n)
		data[i + 1] = data[i];
	data[i + 1] = n;
}

bool	already_exists(int n, t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->array[i] == n)
			return (true);
		i--;
	}
	return (false);
}

int	fill_element(t_stack *stack, char *arg)
{
	unsigned int	j;
	int				n;
	int				status;
	char			**array;

	j = 0;
	status = 0;
	array = ft_split(arg, SPACE);
	while (array[j] && !status)
	{
		if (validate_int(array[j]))
			status = 1;
		if (atoiv(array[j], &n))
			status = 2;
		if (already_exists(n, stack))
			status = 3;
		else
			stack->array[++stack->top] = n;
		j++;
	}
	free_array((void **)array);
	return (status);
}

t_stack	*get_stack(int size, char **args)
{
	unsigned int	i;
	int				status;
	t_stack			*stack;

	if (size < 1)
		exit(0);
	i = 0;
	status = 0;
	stack = initialize(STACK_BUFFER);
	while (args[i] && !status)
		status = fill_element(stack, args[i++]);
	if (status)
	{
		free_stack(stack);
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(status);
	}
	reverse_array(stack->array, stack->top + 1);
	return (stack);
}
