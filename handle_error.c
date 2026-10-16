/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: samudgal <samudgal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 16:52:02 by samudgal      #+#    #+#                 */
/*   Updated: 2026/05/26 14:17:57 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "utils_libft/utils_libft.h"

void	handle_error(t_list **stack)
{
	if (stack && *stack)
		ft_lstclear(stack, free);
	write(2, "Error\n", 6);
	exit (1);
}

int	write_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}
