/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: samudgal <samudgal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/21 15:45:23 by samudgal      #+#    #+#                 */
/*   Updated: 2026/05/26 14:18:35 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b, t_operation *ops)
{
	int	bit_position;
	int	size;
	int	bits_done;

	bit_position = 0;
	size = ft_lstsize(*stack_a);
	while (!is_sorted(stack_a))
	{
		bits_done = 0;
		while (bits_done < size)
		{
			if (((*stack_a)->index >> bit_position) & 1)
				ra(stack_a, ops);
			else
				pb(stack_a, stack_b, ops);
			bits_done++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, ops);
		bit_position++;
	}
}
