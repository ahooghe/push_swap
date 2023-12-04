/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:44:19 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 13:20:30 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *src, int i)
{
	int		n;
	char	*ptr;
	char	c;

	c = (char)i;
	n = 0;
	ptr = 0;
	while (src[n])
	{
		if (src[n] == c)
			ptr = (char *)(src + n);
		n++;
	}
	if (src[n] == c)
		ptr = (char *)(src + n);
	return (ptr);
}
