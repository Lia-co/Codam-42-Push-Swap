/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:32:12 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:42:28 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "utils_libft/utils_libft.h"

void	push(t_list **src, t_list **dst)
{
	t_list	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = node_to_push->next;
	node_to_push->next = *dst;
	*dst = node_to_push;
}

void	pa(t_list **stack_a, t_list **stack_b, t_operation *ops)
{
	push(stack_b, stack_a);
	if (ops)
		ops->op_count[PA]++;
	if (ops && ops->hide == false)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, t_operation *ops)
{
	push(stack_a, stack_b);
	if (ops)
		ops->op_count[PA]++;
	if (ops && ops->hide == false)
		write(1, "pb\n", 3);
}
