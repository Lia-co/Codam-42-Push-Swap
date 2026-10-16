/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_disorder.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: samudgal <samudgal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/01 16:47:06 by sliang        #+#    #+#                 */
/*   Updated: 2026/05/26 14:17:50 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

float	compute_disorder(t_list *stack_a)
{
	float	mistakes;
	float	total_pairs;
	t_list	*current_node;
	t_list	*next_node;

	mistakes = 0;
	total_pairs = 0;
	current_node = stack_a;
	while (current_node->next != NULL)
	{
		next_node = current_node->next;
		while (next_node)
		{
			if (next_node->content < current_node->content)
				mistakes++;
			next_node = next_node->next;
			total_pairs++;
		}
		current_node = current_node->next;
	}
	return (mistakes / total_pairs);
}
