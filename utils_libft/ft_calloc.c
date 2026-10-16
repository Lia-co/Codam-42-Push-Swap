/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:43:54 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:43:56 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	allmem;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	else
	{
		allmem = nmemb * size;
		ptr = malloc(allmem);
		if (!ptr)
			return (NULL);
		else
			ft_bzero(ptr, allmem);
		return (ptr);
	}
}
