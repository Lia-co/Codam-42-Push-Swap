/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: samudgal <samudgal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 16:01:56 by sliang        #+#    #+#                 */
/*   Updated: 2026/05/26 14:18:10 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_dup(t_list *stack)
{
	t_list	*tmp;
	t_list	*check;

	tmp = stack;
	while (tmp)
	{
		check = tmp->next;
		while (check)
		{
			if (tmp->content == check->content)
				handle_error(&stack);
			check = check->next;
		}
		tmp = tmp->next;
	}
}

t_list	*make_list(char **arr_str)
{
	int		i;
	t_list	*stack_a;
	t_list	*node;

	stack_a = NULL;
	node = NULL;
	i = 0;
	if (!arr_str || !arr_str[i])
		handle_error(NULL);
	while (arr_str[i])
	{
		node = ft_lstnew(ft_atoi(arr_str[i]));
		if (!node)
			handle_error(&stack_a);
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	check_dup(stack_a);
	return (stack_a);
}
