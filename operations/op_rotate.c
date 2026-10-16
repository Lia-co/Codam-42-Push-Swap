/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:25:37 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:42:52 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "utils_libft/utils_libft.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = tmp->next;
	last = ft_lstlast(*stack);
	last->next = tmp;
	tmp->next = NULL;
}

void	ra(t_list **stack_a, t_operation *ops)
{
	rotate(stack_a);
	if (ops)
		ops->op_count[RA]++;
	if (ops && ops->hide == false)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, t_operation *ops)
{
	rotate(stack_b);
	if (ops)
		ops->op_count[RB]++;
	if (ops && ops->hide == false)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, t_operation *ops)
{
	rotate(stack_a);
	rotate(stack_b);
	if (ops)
		ops->op_count[RR]++;
	if (ops && ops->hide == false)
		write(1, "rr\n", 3);
}
