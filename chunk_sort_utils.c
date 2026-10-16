/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:56:29 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:41:51 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*array_from_stack(t_list **stack, int size)
{
	int		*array;
	int		i;
	t_list	*current;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	current = *stack;
	while (current && i < size)
	{
		array[i] = current->content;
		current = current->next;
		i++;
	}
	return (array);
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (!array)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

void	assign_index(t_list *stack_a, int *sorted_array, int size)
{
	t_list	*current;
	int		i;

	current = stack_a;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (sorted_array[i] == current->content)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	make_index(t_list **stack_a)
{
	int	size;
	int	*array;

	if (!stack_a || !*stack_a)
		return ;
	size = ft_lstsize(*stack_a);
	if (size <= 0)
		return ;
	array = array_from_stack(stack_a, size);
	array = sort_array(array, size);
	assign_index(*stack_a, array, size);
	free(array);
}
