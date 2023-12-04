/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:34:31 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 13:20:30 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_amountinputs(unsigned int n)
{
	int	amountinputs;

	amountinputs = 0;
	while (n >= 1)
	{
		amountinputs++;
		n /= 10;
	}
	return (amountinputs);
}

static char	*ft_generate(char *numberstring, unsigned int input, int len)
{
	if (input != 0)
		numberstring = malloc(sizeof(char) * (len + 1));
	else
		return (numberstring = ft_strdup("0"));
	if (!numberstring)
		return (0);
	numberstring[len--] = '\0';
	while (len)
	{
		numberstring[len] = (input % 10) + '0';
		input /= 10;
		len--;
	}
	return (numberstring);
}

char	*ft_uitoa(unsigned int n)
{
	char	*numberstring;

	numberstring = 0;
	numberstring = ft_generate(numberstring, n, ft_amountinputs(n));
	if (!(numberstring))
		return (0);
	return (numberstring);
}
