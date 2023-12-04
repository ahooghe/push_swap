/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:34:15 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 13:20:30 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtok_r(char *str, const char *delim, char **save_ptr)
{
	char	*end;

	if (str == NULL)
		str = *save_ptr;
	if (*str == '\0')
	{
		*save_ptr = str;
		return (NULL);
	}
	str += ft_strspn(str, delim);
	if (*str == '\0')
	{
		*save_ptr = str;
		return (NULL);
	}
	end = str + ft_strcspn(str, delim);
	if (*end == '\0')
	{
		*save_ptr = end;
		return (str);
	}
	*end = '\0';
	*save_ptr = end + 1;
	return (str);
}
