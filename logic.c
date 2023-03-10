/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:13:52 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/10 16:34:11 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_number(long long num, t_stack **stack_at)
{
	t_stack		*current;
	long long	index;

	index = 0;
	current = (*stack_at);
	while (current != NULL)
	{
		if (current->num == num)
			return (index);
		index++;
		current = current->next;
	}
	return (index);
}

void	ft_index(t_stack **stack_a, t_stack **stack_at)
{
	t_stack	*current;

	current = (*stack_a);
	while (current != NULL)
	{
		current->num = ft_number(current->num, stack_at);
		current = current->next;
	}
}

void	ft_pre_sort(t_stack **stack_at, t_stack **stack_b)
{
	while ((*stack_at))
	{
		if ((*stack_at)->num == ft_min((*stack_at)))
			ft_pp(stack_at, stack_b, 'n');
		else
			ft_rt(stack_at);
	}
	while ((*stack_b) != NULL)
		ft_pp(stack_b, stack_at, 'n');
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	long long	i;
	long long	j;
	long long	range;
	long long	num;

	i = 0;
	range = 0;
	while (ft_max((*stack_a)) >> range != 0)
		range++;
	while (i < range)
	{
		j = 0;
		while ((j < argc))
		{
			num = (*stack_a)->num;
			if (((num >> i) & 1) == 0)
				ft_pp(stack_a, stack_b, 'b');
			else
				ft_rr(stack_a, stack_b, 'a');
			j++;
		}
		while ((*stack_b) != NULL)
			ft_pp(stack_b, stack_a, 'a');
		i++;
	}
}

void	ft_logic(t_stack **stack_a, t_stack **stack_b, int argc,
		t_stack **stack_at)
{
	if (ft_sorted(*stack_a) == 0)
		exit(0);
	ft_pre_sort(stack_at, stack_b);
	ft_index(stack_a, stack_at);
	ft_clean_stack((*stack_at));
	ft_big_sort(stack_a, stack_b, argc);
	ft_clean_stack((*stack_a));
}
