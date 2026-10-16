/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   selection_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: samudgal <samudgal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 15:34:15 by samudgal      #+#    #+#                 */
/*   Updated: 2026/05/24 17:53:00 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		find_min_position(t_list **stack_b);
int		find_smallest(t_list *stack);

void	selection_sort(t_list **stack_a, t_list **stack_b, t_operation *ops)
{
	int	min_position;
	int	size;

	while (ft_lstsize(*stack_a) > 3)
	{
		size = ft_lstsize(*stack_a);
		min_position = find_min_position(stack_a);
		if ((*stack_a)->index == find_smallest(*stack_a))
			pb(stack_a, stack_b, ops);
		else
		{
			if (min_position > size / 2)
				rra(stack_a, ops);
			else
				ra(stack_a, ops);
		}
	}
	sort_three(stack_a, ops);
	while (*stack_b)
		pa(stack_a, stack_b, ops);
}

int	find_min_position(t_list **stack_b)
{
	t_list	*current;
	int		tracker;
	int		position;
	int		current_pos;

	if (!stack_b || !*stack_b)
		return (0);
	current = *stack_b;
	tracker = current->index;
	position = 0;
	current_pos = 0;
	while (current)
	{
		if (current->index < tracker)
		{
			tracker = current->index;
			position = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (position);
}

int	find_smallest(t_list *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if ((stack->index) < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}
