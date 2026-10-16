/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:34:15 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:40:33 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_list **stack_a, t_operation *ops)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		sa(stack_a, ops);
	else if (a > b && b > c)
	{
		sa(stack_a, ops);
		rra(stack_a, ops);
	}
	else if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, ops);
		ra(stack_a, ops);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, ops);
	else if (a < b && b > c && a > c)
		rra(stack_a, ops);
}
