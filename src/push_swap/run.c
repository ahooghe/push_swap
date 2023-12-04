/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:25:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 13:32:14 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/push_swap.h"
#include "../../libft/include/libft.h"

void	run(char *op, t_stack *a, t_stack *b)
{
	if (ft_streq(op, PA))
		push(b, a);
	else if (ft_streq(op, PB))
		push(a, b);
	else if (ft_streq(op, SA))
		swap(a);
	else if (ft_streq(op, SB))
		swap(b);
	else if (ft_streq(op, RA))
		rotate(a);
	else if (ft_streq(op, RB))
		rotate(b);
	else if (ft_streq(op, RRA))
		reverse_rotate(a);
	else if (ft_streq(op, RRB))
		reverse_rotate(b);
	ft_putendl_fd(op, STDOUT_FILENO);
}

void	run_n(char *op, t_stack *a, t_stack *b, int n)
{
	if (n <= 0)
		return ;
	run(op, a, b);
	run_n(op, a, b, n - 1);
}
