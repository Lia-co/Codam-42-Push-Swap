/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:33:22 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 18:14:31 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_push_swap(char **argv, t_flag flag)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_operation	ops;
	float		disorder;

	stack_b = NULL;
	validate_array(&argv[flag.flag_num]);
	init_ops(&ops);
	stack_a = make_list(&argv[flag.flag_num]);
	make_index(&stack_a);
	if (!stack_a || ft_lstsize(stack_a) <= 1 || is_sorted(&stack_a))
	{
		ft_lstclear(&stack_a, free);
		return ;
	}
	disorder = compute_disorder(stack_a);
	select_algo(&flag, &ops, &stack_a, &stack_b);
	if (flag.bench == true)
		print_bench(disorder, &flag, ops);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}

int	main(int argc, char **argv)
{
	t_flag		flag;

	if (argc < 2)
		return (0);
	else
		argv = argv + 1;
	check_flag(argv, &flag);
	do_push_swap(argv, flag);
	return (0);
}
