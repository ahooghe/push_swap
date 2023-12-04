/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:25:50 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 12:31:44 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/general.h"
#include "../../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	stack = get_stack(argc - 1, &argv[1]);
	index_stack(&stack);
	sort(stack);
	free_stack(stack);
	return (0);
}
