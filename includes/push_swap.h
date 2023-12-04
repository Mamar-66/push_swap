/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:50:57 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/04 17:52:42 by omfelk           ###   ########.fr       */
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

/*---------------------folder utile----------------*/
void		ft_bzero(void *s, size_t n);
void		ft_putstr(char *s);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *nptr);
int			len_lst(t_list *lst);
/*-------------------------------------------------*/

/*-------------------folder gest_pile--------------*/
// file add_pile.c
char		*word_nb(char *str, int *start);
bool		cmp(t_list *lst);
void		stack_gest(t_list **lst, char *argv_str);
int			add_stack(t_list *lst, char *str, int *tr);

// folder shots
void		sb(t_list **lst, bool write);
void		sa(t_list **lst, bool write);
void		ss(t_list **lst_a, t_list **lst_b);
void		ra(t_list **lst, bool write);
void		rb(t_list **lst, bool write);
void		rr(t_list **lst_a, t_list **lst_b);
void		pa(t_list **src, t_list **dest);
void		pb(t_list **src, t_list **dest);
void		rra(t_list **lst, bool write);
void		rrb(t_list **lst, bool write);
void		rrr(t_list **lst_a, t_list **lst_b);
/*-------------------------------------------------*/

//error.c
bool		is_not_digit(char *str);
bool		is_double(t_list **lst);

/*--------------folder if_three_n------------------*/
void		one_two_three_n(t_list **lst);
/*-------------------------------------------------*/

#endif
