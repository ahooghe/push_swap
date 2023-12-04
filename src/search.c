/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:27:33 by ahooghe           #+#    #+#             */
/*   Updated: 2023/03/20 14:27:34 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	binary_search(int n, int *data, int size)
{
	int	mid;
	int	left;
	int	right;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + ((right - left) / 2);
		if (data[mid] == n)
			return (true);
		else if (n < data[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (false);
}
