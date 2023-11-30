/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:50:57 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/30 17:37:14 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
}t_list;

/*----------------------------------folder utile-------------------------------------------*/ 
void		ft_bzero(void *s, size_t n);
void		ft_putstr(char *s);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *nptr);

/*----------------------------------folder gest_pile---------------------------------------*/
// file add_pile.c
char		*word_nb(char *str, int *start);
void		stack_gest(t_list **lst, char *argv_str);
int			add_stack(t_list *lst, char *str, int *tr);
// file cmp.c
bool		cmp(int nb1, int nb2);
// folder shots
void		sa_sb(t_list **lst);
void		ss(t_list **lst_a, t_list **lst_b);
void		ra_rb(t_list **lst);
void		rr(t_list **lst_a, t_list **lst_b);

/*-----------------------------------------------------------------------------------------*/

//error.c
bool		is_not_digit(char *str);
bool		is_double(t_list **lst);

#endif
