/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:50:19 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:34:25 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "utils_libft/utils_libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

// define ops list
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef enum e_algo_list
{
	NON_SET,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}				t_algo_list;

typedef struct s_operation
{
	int			op_count[11];
	char		*op_labels;
	bool		hide;
}				t_operation;

typedef struct s_flag
{
	int			flag_num;
	t_algo_list	algorithm;
	bool		bench;
}				t_flag;

// op-utils
void			swap(t_list **stack);
void			push(t_list **src, t_list **dst);
void			rotate(t_list **stack);
void			reverse_rotate(t_list **stack);

// op-buttons
// op_swap.c
void			sa(t_list **stack_a, t_operation *ops);
void			sb(t_list **stack_b, t_operation *ops);
void			ss(t_list **stack_a, t_list **stack_b, t_operation *ops);

// op_push.c
void			pa(t_list **stack_a, t_list **stack_b, t_operation *ops);
void			pb(t_list **stack_a, t_list **stack_b, t_operation *ops);

// op_rotate.c
void			ra(t_list **stack_a, t_operation *ops);
void			rb(t_list **stack_b, t_operation *ops);
void			rr(t_list **stack_a, t_list **stack_b, t_operation *ops);

// op_reverse_rotate.c
void			rra(t_list **stack_a, t_operation *ops);
void			rrb(t_list **stack_b, t_operation *ops);
void			rrr(t_list **stack_a, t_list **stack_b, t_operation *ops);

// sort_small_strategy.c
void			sort_three(t_list **stack_a, t_operation *ops);

// compute_disorder.c
float			compute_disorder(t_list *stack_a);

// parser_utils.c
int				is_sorted(t_list **stack_a);
long			ft_atoi_long(const char *nptr);
void			validate_array(char **res);

// make_list.c
t_list			*make_list(char **arr_str);
void			check_dup(t_list *stack);

// handle_error.c
void			handle_error(t_list **stack);
int				write_error(void);

// check_flag.c
int				check_flag(char *argv[], t_flag *flag);
void			set_flag(char *argv[], t_flag *flag);

// init_ops.c
void			init_ops(t_operation *ops);

// bench.c
void			print_bench(float disorder, t_flag *flag, t_operation ops);
void			print_disorder(float disorder);
void			print_strategy(float disorder, t_flag *flag);
void			print_total_ops(t_operation ops);
void			print_per_ops(t_operation ops);

// selection_sort.c
int				find_min_position(t_list **stack_b);
int				find_smallest(t_list *stack);
void			selection_sort(t_list **stack_a, t_list **stack_b,
					t_operation *ops);

// chunk_sort
void			make_index(t_list **stack_a);
void			chunk_sort(t_list **stack_a, t_list **stack_b,
					t_operation *ops);

// radix_sort
void			radix_sort(t_list **stack_a, t_list **stack_b,
					t_operation *ops);

// radix_sort.c
void			radix_sort(t_list **stack_a, t_list **stack_b,
					t_operation *ops);

// adaptive_sort.c
void			adaptive_sort(t_list **stack_a, t_list **stack_b,
					t_operation *ops);

// select_algo.c
void			select_algo(t_flag *flag, t_operation *ops,
					t_list **stack_a, t_list **stack_b);

#endif
