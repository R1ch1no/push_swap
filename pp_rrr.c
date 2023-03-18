/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:28:26 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/18 17:19:56 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_max(t_stack *stack)
{
	long long	max;
	t_stack		*current;

	current = stack;
	max = current->num;
	current = current->next;
	while (current != NULL)
	{
		if (max < current->num)
			max = current->num;
		current = current->next;
	}
	return (max);
}

void	ft_pp(t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_b)->next = NULL;
	}
	else
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_rrt(t_stack **stack)
{
	t_stack	*start;
	t_stack	*current;
	t_stack	*end;

	start = *stack;
	current = *stack;
	while (current->next != NULL)
	{
		if (current->next->next == NULL)
			end = current;
		current = current->next;
	}
	current->next = start;
	end->next = NULL;
	*stack = current;
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
	{
		ft_rrt(stack_a);
		write(1, "rra\n", 4);
	}
	if (c == 'b')
	{
		ft_rrt(stack_b);
		write(1, "rrb\n", 4);
	}
	if (c == 'r')
	{
		ft_rrt(stack_a);
		ft_rrt(stack_b);
		write(1, "rrr\n", 4);
	}
}
