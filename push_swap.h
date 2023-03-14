/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:35:50 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/14 19:47:03 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_medium
{
	int				argc;
	int				no;
}					t_medium;

typedef struct s_stack
{
	long long		num;
	struct s_stack	*next;
}					t_stack;

//utils
long long			ft_max(t_stack *stack);
long long			ft_min(t_stack *stack);
long long			ft_last_node(t_stack *stack);
int					ft_repeat(t_stack *stack);
int					ft_sorted(t_stack *stack);
long				ft_atoi(const char *str, t_medium *medium);
void				ft_clean_stack(t_stack *stack);
//moves
void				ft_ss(t_stack *stack_a, t_stack *stack_b, char c);
void				ft_pp(t_stack **stack_a, t_stack **stack_b, char c);
void				ft_rt(t_stack **stack);
void				ft_rr(t_stack **stack_a, t_stack **stack_b, char c);
void				ft_rrt(t_stack **stack);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b, char c);
//logic
void				ft_sort_three(t_stack **stack_a, t_stack **stack_at,
						t_medium *medium, int clean);
void				ft_sort_five(t_stack **stack_a, t_stack **stack_b,
						t_medium *medium);
void				ft_logic(t_stack **stack_a, t_stack **stack_b, int argc,
						t_stack **stack_at);
#endif
