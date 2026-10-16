/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_ops.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/24 17:04:26 by sliang        #+#    #+#                 */
/*   Updated: 2026/05/24 17:04:35 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_ops(t_operation *ops)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		ops->op_count[i] = 0;
		i++;
	}
	ops->op_labels = ("sa sb ss pa pb ra rb rr rra rrb rrr ");
	ops->hide = false;
	return ;
}
