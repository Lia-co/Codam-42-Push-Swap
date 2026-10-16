/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:34:15 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/26 18:14:00 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	adaptive_sort(t_list **stack_a, t_list **stack_b, t_operation *ops)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a, ops);
	else if (size == 3)
		sort_three(stack_a, ops);
	else if (size <= 10)
		selection_sort(stack_a, stack_b, ops);
	else if (size <= 150)
	{
		if ((compute_disorder(*stack_a) < 0.2))
			selection_sort(stack_a, stack_b, ops);
		else
			chunk_sort(stack_a, stack_b, ops);
	}
	else
	{
		if (compute_disorder(*stack_a) < 0.5)
			chunk_sort(stack_a, stack_b, ops);
		else
			radix_sort(stack_a, stack_b, ops);
	}
}
