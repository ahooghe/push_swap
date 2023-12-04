/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:34:31 by ahooghe           #+#    #+#             */
/*   Updated: 2023/05/11 13:20:30 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_amountinputs(long n)
{
	size_t	amountinputs;
	int		isneg;

	amountinputs = 0;
	isneg = 0;
	if (n < 0)
	{
		amountinputs++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		amountinputs++;
		n /= 10;
	}
	return (amountinputs);
}

static char	*ft_generate(char *numberstring, long input, int len, int isneg)
{
	if (input != 0)
		numberstring = malloc(sizeof(char) * (len + 1));
	else
		return (numberstring = ft_strdup("0"));
	if (!numberstring)
		return (0);
	isneg = 0;
	if (input < 0)
	{
		isneg++;
		input = -input;
	}
	numberstring[len] = '\0';
	while (--len)
	{
		numberstring[len] = (input % 10) + '0';
		input /= 10;
	}
	if (isneg == 1)
		numberstring[0] = '-';
	else
		numberstring[0] = (input % 10) + '0';
	return (numberstring);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*numberstring;
	long	input;
	int		isneg;

	input = n;
	len = ft_amountinputs(input);
	numberstring = 0;
	isneg = 0;
	numberstring = ft_generate(numberstring, input, len, isneg);
	if (!(numberstring))
		return (0);
	return (numberstring);
}
