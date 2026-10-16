/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:32:04 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:42:45 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "utils_libft/utils_libft.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*before_last;
	t_list	*last;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	last = *stack;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **stack_a, t_operation *ops)
{
	reverse_rotate(stack_a);
	if (ops)
		ops->op_count[RRA]++;
	if (ops && ops->hide == false)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, t_operation *ops)
{
	reverse_rotate(stack_b);
	if (ops)
		ops->op_count[RRB]++;
	if (ops && ops->hide == false)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, t_operation *ops)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (ops)
		ops->op_count[RRR]++;
	if (ops && ops->hide == false)
		write(1, "rrr\n", 4);
}
