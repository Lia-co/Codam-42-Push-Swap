/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bench.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/24 17:00:13 by sliang        #+#    #+#                 */
/*   Updated: 2026/05/26 12:08:55 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_bench(float disorder, t_flag *flag, t_operation ops)
{
	print_disorder(disorder);
	print_strategy(disorder, flag);
	print_total_ops(ops);
	print_per_ops(ops);
}

void	print_disorder(float disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((disorder * 100), 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd((int)(disorder * 100) % 100, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_strategy(float disorder, t_flag *flag)
{
	if (flag->algorithm == ADAPTIVE || flag->algorithm == NON_SET)
	{
		if (disorder < (float)0.2)
			ft_putstr_fd("[bench] strategy: Adaptive / O(n^2) ", 2);
		else if (disorder >= (float)0.2 && disorder < (float)0.5)
			ft_putstr_fd("[bench] strategy: Adaptive / O(n√n) ", 2);
		else if (disorder >= (float)0.5)
			ft_putstr_fd("[bench] strategy: Adaptive / O(n log n) ", 2);
	}
	else if (flag->algorithm == SIMPLE)
		ft_putstr_fd("[bench] strategy: Simple / O(n^2) ", 2);
	else if (flag->algorithm == MEDIUM)
		ft_putstr_fd("[bench] strategy: Medium / O(n√n) ", 2);
	else if (flag->algorithm == COMPLEX)
		ft_putstr_fd("[bench] strategy: Complex / O(n log n) ", 2);
	ft_putstr_fd("\n", 2);
}

void	print_total_ops(t_operation ops)
{
	int	total_ops;
	int	i;

	total_ops = 0;
	i = 0;
	ft_putstr_fd("[bench] total_ops: ", 2);
	while (i < 11)
	{
		total_ops += ops.op_count[i];
		i++;
	}
	ft_putnbr_fd(total_ops, 2);
	write(2, "\n", 1);
}

void	print_per_ops(t_operation ops)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_putstr_fd("[bench] ", 2);
	while (i < 11)
	{
		if (i == 5)
			ft_putstr_fd("\n[bench] ", 2);
		while (ops.op_labels[j] != ' ')
		{
			write(2, ops.op_labels + j, 1);
			j++;
		}
		j++;
		write(2, ":  ", 3);
		ft_putnbr_fd(ops.op_count[i], 2);
		i++;
		write(2, "  ", 2);
	}
	write(2, "\n", 1);
}
