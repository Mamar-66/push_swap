/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:50:57 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/11 17:21:04 by omfelk           ###   ########.fr       */
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
	int				pose;
	int				shorts_up;
	struct s_list	*next;
}	t_list;

typedef struct s_list_instruction
{
	int			nb_a;
	int			pose_a;
	int			shorts_up_a;
	int			nb_b;
	int			pose_b;
	int			shorts_up_b;
	int			min_c;
	int			scor;
	int			way;
}	instrs;

void	affiche_stack(t_list *stack_a, t_list *stack_b);

/*---------------------folder utile----------------*/
void		ft_bzero(void *s, size_t n);
void		ft_putstr(char *s);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *nptr);
int			len_lst(t_list *lst);
/*-------------------------------------------------*/

/*-------------------folder gest_pile--------------*/
// file add_pile.c
void		stack_gest(t_list **lst, int ac, char **argv_str);
void		three_plus(t_list **lst_a, t_list **lst_b);
void		one_three(t_list **lst_a);
bool		cmp(t_list *lst);
char		*word_nb(char *str, int *start);
// file add_stack.c
int			add_stack(t_list *lst, char *str, int *tr);
void		rang(t_list **lst, int int_max);
int			max(t_list **lst);
/////////////////
// file add_pose.c
void		pre_add_pose(t_list **lst_a, t_list **lst_b);
//////////////////
// file three_plus.c
void		add_pose(t_list **lst);
void		rang_tab(int *tab_all_vall);
void		the_end(t_list **lst);
int			find_mediane(t_list **lst_a);
int			min_nb(t_list **lst);
////////////////////
// at_very_top.c
void		rempl_instrs(t_list **lst_a, t_list **lst_b, int count, instrs **instrs);
void		add_very_top(t_list **lst_a, t_list **lst_b);
int			scor_shorts_up(t_list **lst_a, t_list **lst_b);
int			closer(t_list **lst_a, t_list **lst_b, int min_lst_a, int max_lst_a);
int			nb_closer_moin(t_list **lst_a, t_list **lst_b);
////////////////////
// at_the_bottom.c
void		bottom(t_list **lst_a, t_list **lst_b);
int			nb_closer(t_list **lst_a, t_list **lst_b, instrs **instruction);
int			the_way(t_list **lst_a, t_list **lst_b);
//////////////////
// rang_in_stach_a.c
void		gest_shorts(t_list **lst_a, t_list **lst_b, instrs **lst_instrs);
bool		up_a_and_up_b(t_list **lst_a, t_list **lst_b, instrs **lst_instrs);
void		up_b(t_list **lst_b, instrs **lst_instrs);
void		up_a(t_list **lst_b, instrs **lst_instrs);
/////////////////////
/*---------------------------------------------------*/

/*-----------------folder shots---------------------*/
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
bool		is_not_digit(char **str);
bool		is_double(t_list **lst);

#endif
