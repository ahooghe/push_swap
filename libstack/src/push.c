/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:20:44 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 11:52:26 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	push(t_stack *from, t_stack *to)
{
	if (from->top == -1)
		return ;
	to->array[++to->top] = from->array[from->top--];
}
