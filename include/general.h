/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:17:01 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 12:27:32 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include "../libstack/include/stack.h"

# define SPACE ' '
# define STACK_BUFFER 1024

int		abs(int n);
bool	atoiv(const char *str, int *overflow);
void	free_array(void **array);
void	free_stack(t_stack *stack);
void	message_and_exit(t_stack *stack, char **ops, int status);
void	reverse_array(int *array, size_t size);
bool	is_sorted(t_stack *stack);
void	insertion_sort(int array[], size_t size);
t_stack	*get_stack(int size, char **args);

#endif
