/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 17:52:13 by sliang            #+#    #+#             */
/*   Updated: 2026/05/28 17:42:14 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	select_algo(t_flag *flag, t_operation *ops, t_list **stack_a,
		t_list **stack_b)
{
	if (flag->algorithm == SIMPLE)
		selection_sort(stack_a, stack_b, ops);
	else if (flag->algorithm == MEDIUM)
		chunk_sort(stack_a, stack_b, ops);
	else if (flag->algorithm == COMPLEX)
		radix_sort(stack_a, stack_b, ops);
	else if (flag->algorithm == ADAPTIVE || flag->algorithm == NON_SET)
		adaptive_sort(stack_a, stack_b, ops);
}
