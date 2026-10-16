/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:12:56 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/18 17:02:53 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstclear(t_list **lst, void (*del)(void*)) //should it be int here 
{
	t_list	*cpy;

	if (!lst || !*lst || !del)
		return ;
	while (*lst != NULL)
	{
		cpy = (*lst)->next;
		free(*lst);
		*lst = cpy;
	}
	*lst = NULL;
}
