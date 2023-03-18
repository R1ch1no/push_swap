/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:03:23 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/18 17:19:53 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_min(t_stack *stack)
{
	t_stack		*current;
	t_stack		*start;
	long long	min;

	start = stack;
	current = stack;
	min = current->num;
	while (current != NULL)
	{
		if (min > current->num)
			min = current->num;
		current = current->next;
	}
	current = start;
	return (min);
}

void	ft_st(t_stack *stack)
{
	long long	tmp1;
	long long	tmp2;

	tmp1 = stack->num;
	tmp2 = stack->next->num;
	stack->num = tmp2;
	stack->next->num = tmp1;
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b, char c)
{
	if (c == 'a')
	{
		ft_st(stack_a);
		write(1, "sa\n", 3);
	}
	if (c == 'b')
	{
		ft_st(stack_b);
		write(1, "sb\n", 3);
	}
	if (c == 's')
	{
		ft_st(stack_a);
		ft_st(stack_b);
		write(1, "ss\n", 3);
	}
}

void	ft_rt(t_stack **stack)
{
	t_stack	*start;
	t_stack	*current;
	t_stack	*first;

	start = *stack;
	current = *stack;
	first = current->next;
	while (current->next != NULL)
		current = current->next;
	current->next = start;
	start->next = NULL;
	*stack = first;
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
	{
		ft_rt(stack_a);
		write(1, "ra\n", 3);
	}
	if (c == 'b')
	{
		ft_rt(stack_b);
		write(1, "rb\n", 3);
	}
	if (c == 'r')
	{
		ft_rt(stack_a);
		ft_rt(stack_b);
		write(1, "rr\n", 3);
	}
}
