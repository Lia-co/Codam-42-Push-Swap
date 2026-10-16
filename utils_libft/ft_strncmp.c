/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sliang <sliang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/20 17:47:40 by sliang        #+#    #+#                 */
/*   Updated: 2026/05/21 15:23:35 by sliang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
    The strncmp() function compares the two strings s1 and s2 only the first n 
	bytes. The comparison is done using unsigned characters.
RETURN VALUE
    return an integer: 0, positive or negative
LOGIC
	1. typecasting s1 and s2.
	2. return NULL when n = 0.
	3. compare s1 and s2 character by character at most n bytes
	4. return the difference when it first time occures
*/

#include "pushswap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
