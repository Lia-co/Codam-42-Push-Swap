/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:45:10 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:32:07 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "utils_libft/utils_libft.h"
#include <stdio.h>

int	is_sorted(t_list **stack_a)
{
	t_list	*current;

	if (!stack_a || !*stack_a)
		return (1);
	if (ft_lstsize(*stack_a) == 1)
	{
		ft_lstclear(stack_a, free);
		return (1);
	}
	current = *stack_a;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		else
			current = current->next;
	}
	return (1);
}

long	ft_atoi_long(const char *nptr)
{
	long		i;
	int			sign;
	long		result;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	result = 0;
	while ((nptr[i]) && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void	validate_array(char **str)
{
	int		j;
	int		k;
	long	num;

	j = 0;
	if (str[j][0] == '\0')
		write_error();
	while (str[j])
	{
		k = 0;
		if (str[j][k] == '-' || str[j][k] == '+')
			k++;
		while (str[j][k])
		{
			if (!ft_isdigit(str[j][k]))
				handle_error(NULL);
			k++;
		}
		num = 0;
		num = ft_atoi_long(str[j]);
		if ((num < INT_MIN) || (num > INT_MAX))
			handle_error(NULL);
		j++;
	}
	return ;
}
