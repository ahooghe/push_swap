/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:25:43 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 12:31:25 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	between(int n, int min, int max)
{
	return (n >= min && n <= max);
}

static int	find_from_top(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (between(a->array[i], min, max))
			return (i);
		i++;
	}
	return (-1);
}

static int	find_from_bottom(t_stack *a, int min, int max)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		if (between(a->array[i], min, max))
			return (i);
		i--;
	}
	return (-1);
}

void	move_to_top(t_stack *a, int min, int max)
{
	int	i;
	int	index[2];

	index[0] = find_from_top(a, min, max);
	index[1] = find_from_bottom(a, min, max);
	if (index[0] < a->top - index[1])
		i = index[0];
	else
		i = index[1];
	smart_rotate_a(a, a->array[i]);
}

void	move_min_or_max_to_top(t_stack *b)
{
	int	i;
	int	index[2];

	index[0] = _index(b, min(b));
	index[1] = _index(b, max(b));
	if (index[0] < b->top - index[1])
		i = index[0];
	else
		i = index[1];
	smart_rotate_b(b, b->array[i]);
}
