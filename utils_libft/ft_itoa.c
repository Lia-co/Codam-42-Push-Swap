/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:44:19 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:44:48 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_len(int n);

// convert int to char function
char	*ft_itoa(int n)
{
	char	*chr;
	int		i;
	long	num;

	num = n;
	i = ft_len(num);
	chr = ft_calloc((i + 1), sizeof(char));
	if (!chr)
		return (NULL);
	if (num < 0)
	{
		chr[0] = '-';
		num = -num;
	}
	if (num == 0)
		chr[0] = '0';
	while (num > 0)
	{
		chr[i - 1] = num % 10 + 48;
		num = num / 10;
		i--;
	}
	return (chr);
}

// integer length calculation function
static int	ft_len(int n)
{
	int		len;
	long	num;

	num = n;
	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}
