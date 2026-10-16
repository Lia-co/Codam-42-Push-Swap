/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:45:52 by samudgal          #+#    #+#             */
/*   Updated: 2026/05/28 17:45:56 by samudgal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_LIBFT_H
# define UTILS_LIBFT_H
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// linkedlist stack
typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_itoa(int n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);

#endif
