/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:45:13 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:45:21 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*chr;
	long	num;

	num = n;
	chr = ft_itoa(num);
	if (chr == NULL)
		return ;
	ft_putstr_fd(chr, fd);
	free(chr);
}
