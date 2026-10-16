/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_flag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/25 18:42:17 by sliang        #+#    #+#                 */
/*   Updated: 2026/05/26 12:11:01 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_flag(char *argv[], t_flag *flag);

int	check_flag(char *argv[], t_flag *flag)
{
	unsigned int	i;

	i = 0;
	flag->flag_num = 0;
	flag->algorithm = NON_SET;
	flag->bench = false;
	while (i < 2 && argv[i])
	{
		set_flag(&argv[i], flag);
		i++;
	}
	flag->flag_num = (flag->bench) + (bool)(flag->algorithm != NON_SET);
	return (flag->flag_num);
}

void	set_flag(char *argv[], t_flag *flag)
{
	if (ft_strncmp(*argv, "--bench", 8) == 0 && flag->bench == false)
		flag->bench = true;
	else if (flag->algorithm == NON_SET && !ft_strncmp(*argv, "--simple", 9))
		flag->algorithm = SIMPLE;
	else if (flag->algorithm == NON_SET && !ft_strncmp(*argv, "--medium", 9))
		flag->algorithm = MEDIUM;
	else if (flag->algorithm == NON_SET && !ft_strncmp(*argv, "--complex", 10))
		flag->algorithm = COMPLEX;
	else if (flag->algorithm == NON_SET && !ft_strncmp(*argv, "--adaptive", 11))
		flag->algorithm = ADAPTIVE;
}
