/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:50:39 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/18 16:56:47 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*cpy;

	count = 0;
	cpy = lst;
	while (cpy)
	{
		cpy = cpy->next;
		count++;
	}
	return (count);
}
