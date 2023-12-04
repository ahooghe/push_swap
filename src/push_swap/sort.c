/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:27:05 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 12:32:11 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/general.h"
#include "../../include/push_swap.h"

void	sort(t_stack *stack)
{
	t_stack	*new;

	if (is_sorted(stack) || stack->top <= 0)
		return ;
	new = initialize(stack->size);
	if (stack->top < SORT_COMPLEX_LIMIT)
		sort_small(stack, new);
	else
		sort_complex(stack, new);
	free_stack(new);
}
