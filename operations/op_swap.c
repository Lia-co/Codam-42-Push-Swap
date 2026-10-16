/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:42:06 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:43:18 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "utils_libft/utils_libft.h"

// consists of swap buttons sa,sb,ss

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **stack_a, t_operation *ops)
{
	swap(stack_a);
	if (ops)
		ops->op_count[SA]++;
	if (ops && ops->hide == false)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, t_operation *ops)
{
	swap(stack_b);
	if (ops)
		ops->op_count[SB]++;
	if (ops && ops->hide == false)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, t_operation *ops)
{
	swap(stack_a);
	swap(stack_b);
	if (ops)
		ops->op_count[SS]++;
	if (ops && ops->hide == false)
		write(1, "ss\n", 3);
}
