/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:34:01 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 13:22:43 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	replace_s(char **newstr, char *p, const char *r, size_t slen)
{
	char	*old;
	size_t	olen;
	size_t	rlen;

	old = *newstr;
	olen = ft_strlen(old);
	rlen = ft_strlen(r);
	*newstr = malloc((olen - slen + rlen + 1) * sizeof(*newstr));
	if (*newstr == NULL)
	{
		free(old);
		return ;
	}
	ft_memcpy(*newstr, old, p - old);
	ft_memcpy(*newstr + (p - old), r, rlen);
	ft_memcpy(*newstr + (p - old) + rlen, p + slen, olen - slen - (p - old));
	ft_memset(*newstr + olen - slen + rlen, 0, 1);
	free(old);
}

char	*ft_strreplace(char **s, const char *search, const char *replace)
{
	char	*p;
	char	*newstr;
	size_t	search_len;

	if (!search || !replace)
		return (*s);
	newstr = ft_strdup(*s);
	search_len = ft_strlen(search);
	p = ft_strnstr(newstr, search, ft_strlen(newstr));
	while (p)
	{
		p = ft_strnstr(newstr, search, ft_strlen(newstr));
		replace_s(&newstr, p, replace, search_len);
	}
	free(*s);
	*s = newstr;
	return (*s);
}
