/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:25:23 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 13:31:58 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/include/libft.h"
#include "../../include/general.h"

static int	*sorted_array_copy(t_stack *stack)
{
	int		*copy;
	size_t	size;

	size = stack->top + 1;
	copy = malloc(size * sizeof(*copy));
	ft_memcpy(copy, stack->array, size * sizeof(*copy));
	insertion_sort(copy, size);
	return (copy);
}

void	index_stack(t_stack **stack)
{
	int		*copy;
	int		i;
	size_t	pos;
	int		*array;

	i = 0;
	array = ft_calloc((*stack)->top + 1, sizeof(*array));
	copy = sorted_array_copy(*stack);
	while (i <= (*stack)->top)
	{
		pos = 0;
		while (copy[pos] != (*stack)->array[i])
			pos++;
		array[i++] = pos;
	}
	ft_memcpy((*stack)->array, array, ((*stack)->top + 1) * sizeof(*array));
	free(copy);
	free(array);
}

int	_index(t_stack *stack, int n)
{
	int	i;

	i = stack->top;
	while (stack->array[i] != n && i >= 0)
		i--;
	return (i);
}
