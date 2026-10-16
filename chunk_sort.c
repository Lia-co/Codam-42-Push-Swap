/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:23:34 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:41:40 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int	chunk_squareroot(t_list **stack_a)
{
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	if (size <= 0)
		return (0);
	i = 1;
	while (i * i <= size)
	{
		if (i * i == size)
			return (i);
		i++;
	}
	i--;
	return (i);
}

int	find_max_int(t_list **stack_b)
{
	t_list	*current;
	int		tracker;
	int		position;
	int		current_pos;

	if (!stack_b || !*stack_b)
		return (-1);
	tracker = -1;
	position = 0;
	current_pos = 0;
	current = *stack_b;
	while (current)
	{
		if (current->index > tracker)
		{
			tracker = current->index;
			position = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (position);
}

void	send_to_stack_a(t_list **stack_a, t_list **stack_b, t_operation *ops)
{
	int	max;
	int	size;

	while (*stack_b)
	{
		size = ft_lstsize(*stack_b);
		max = find_max_int(stack_b);
		while (max != 0)
		{
			if (max <= size / 2)
				rb(stack_b, ops);
			else
				rrb(stack_b, ops);
			max = find_max_int(stack_b);
		}
		pa(stack_a, stack_b, ops);
	}
}

void	chunk_sort(t_list **stack_a, t_list **stack_b, t_operation *ops)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = chunk_squareroot(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index < i)
		{
			pb(stack_a, stack_b, ops);
			rb(stack_b, ops);
			i++;
		}
		else if ((*stack_a)->index <= i + chunk_size)
		{
			pb(stack_a, stack_b, ops);
			i++;
		}
		else
		{
			ra(stack_a, ops);
		}
	}
	send_to_stack_a(stack_a, stack_b, ops);
}
