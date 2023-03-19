/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:16:12 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/19 14:06:46 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack_a, t_stack **stack_at)
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
}

int	ft_min_place(t_stack *stack)
{
	t_stack	*current;
	int		place;

	current = stack;
	place = 0;
	while (current != NULL && current->num != ft_min(stack))
	{
		current = current->next;
		place++;
	}
	return (place);
}

void	ft_put_away(t_stack **stack_a, t_stack **stack_b, int place)
{
	t_stack	*current;
	int		size;

	current = (*stack_a);
	size = 0;
	place = ft_min_place((*stack_a));
	while (current->next != NULL)
	{
		current = current->next;
		size++;
	}
	if (size == place)
		ft_rrr(stack_a, stack_b, 'a');
	else if (place == (size - 1))
	{
		ft_rrr(stack_a, stack_b, 'a');
		ft_rrr(stack_a, stack_b, 'a');
	}
	else if (place == 2)
	{
		ft_rr(stack_a, stack_b, 'a');
		ft_rr(stack_a, stack_b, 'a');
	}
	else if (place == 1)
		ft_rr(stack_a, stack_b, 'a');
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b, t_medium *medium)
{
	if (medium->argc == 5 && ft_sorted((*stack_a)) == 1)
	{
		ft_put_away(stack_a, stack_b, 0);
		ft_pp(stack_a, stack_b, 'b');
		ft_put_away(stack_a, stack_b, 0);
		ft_pp(stack_a, stack_b, 'b');
		ft_sort_three(stack_a, stack_b);
		ft_pp(stack_b, stack_a, 'a');
		ft_pp(stack_b, stack_a, 'a');
	}
	if (medium->argc == 4 && ft_sorted((*stack_a)) == 1)
	{
		ft_put_away(stack_a, stack_b, 0);
		ft_pp(stack_a, stack_b, 'b');
		ft_sort_three(stack_a, stack_b);
		ft_pp(stack_b, stack_a, 'a');
	}
}
