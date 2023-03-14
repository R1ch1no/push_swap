/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:16:12 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/14 19:47:02 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_done(t_stack **stack_a, t_stack **stack_at, t_medium *medium, int clean)
{
    if(clean == 0)
    {
	ft_clean_stack((*stack_a));
	ft_clean_stack((*stack_at));
	free(medium);
    }
}

void    ft_sort_two(t_stack **stack_a, t_stack **stack_b)
{
    if((*stack_a)->num < (*stack_a)->next->num)
        ft_ss((*stack_a), (*stack_b), 'b');
}

void	ft_sort_three(t_stack **stack_a, t_stack **stack_at, t_medium *medium, int clean)
{
	if ((*stack_a)->num > (*stack_a)->next->num
		&& (*stack_a)->next->num > (*stack_a)->next->next->num)
	{
		ft_ss((*stack_a), (*stack_at), 'a');
		ft_rrr(stack_a, stack_at, 'a');
	}
	if ((*stack_a)->num < (*stack_a)->next->num
		&& (*stack_a)->next->num > (*stack_a)->next->next->num
		&& (*stack_a)->num < (*stack_a)->next->next->num)
	{
		ft_rrr(stack_a, stack_at, 'a');
		ft_ss((*stack_a), (*stack_at), 'a');
	}
	if ((*stack_a)->num > (*stack_a)->next->num
		&& (*stack_a)->next->num < (*stack_a)->next->next->num
		&& (*stack_a)->num < (*stack_a)->next->next->num)
		ft_ss((*stack_a), (*stack_at), 'a');
	if ((*stack_a)->next->next->num < (*stack_a)->num
		&& (*stack_a)->num < (*stack_a)->next->num)
		ft_rrr(stack_a, stack_at, 'a');
	if ((*stack_a)->num > (*stack_a)->next->num
		&& (*stack_a)->num > (*stack_a)->next->next->num
		&& (*stack_a)->next->num < (*stack_a)->next->next->num)
		ft_rr(stack_a, stack_at, 'a');
	ft_done(stack_a, stack_at, medium, clean);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b, t_medium *medium)
{
    ft_pp(stack_a,stack_b, 'b');
    ft_pp(stack_a,stack_b, 'b');
    ft_sort_two(stack_a, stack_b);
    ft_sort_three(stack_a,stack_b,medium, 1);
	ft_done(stack_a, stack_b, medium, 0);
}