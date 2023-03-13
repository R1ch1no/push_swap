/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:44:56 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/13 19:26:35 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

long	ft_count_nums(char **argv)
{
	int	i;
	int	nums;

	i = -1;
	nums = 0;
	while (argv[1][i])
	{
		while (argv[1][i] == ' ' || (argv[1][i] > 8 && argv[1][i] < 14))
			i++;
		nums++;
	}
	return (nums);
}

void	ft_fill_stack_string(t_stack *stack, char **argv, t_medium *medium)
{
	int			i;
	long long	num;
	int			nums;

	i = 0;
	nums = 0;
	while (argv[1][i])
	{
		stack->num = ft_atoi(&argv[1][i], medium);
		num = stack->num;
		nums++;
		if (num > 2147483647 || num < -2147483648)
			medium->no = 1;
		while (argv[1][i] == ' ' || (argv[1][i] > 8 && argv[1][i] < 14)
			|| argv[1][i] == '-' || argv[1][i] == '+')
			i++;
		while ((argv[1][i] <= '9' && argv[1][i] >= '0'))
			i++;
		if (nums < ft_count_nums(argv))
		{
			stack->next = malloc(sizeof(t_stack));
			stack = stack->next;
		}
	}
	stack->next = NULL;
}

void	ft_fill_stack(t_stack *stack, int argc, char **argv, t_medium *medium)
{
	int			i;
	long long	num;

	i = 0;
	while (argv[++i] != NULL)
	{
		if (argv[i])
		{
			stack->num = ft_atoi(argv[i], medium);
			num = stack->num;
			if (num > 2147483647 || num < -2147483648)
				medium->no = 1;
			if (i < argc - 1)
			{
				stack->next = malloc(sizeof(t_stack));
				stack = stack->next;
			}
		}
	}
	stack->next = NULL;
}

void	ft_check_run(t_stack *stack_a, t_stack *stack_b, t_medium *medium,
		t_stack *stack_at)
{
	int	argc;

	argc = medium->argc;
	if (medium->no == 0 && argc > 2)
	{
		if (ft_repeat(stack_a) == 1)
		{
			ft_clean_stack(stack_a);
			ft_clean_stack(stack_at);
		}
		else
			ft_logic(&stack_a, &stack_b, argc - 1, &stack_at);
	}
	else
	{
		ft_clean_stack(stack_a);
		ft_clean_stack(stack_at);
	}
	free(medium);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*stack_at;
	t_medium	*medium;

	if (argc < 2)
		return (0);
	medium = malloc(sizeof(t_medium));
	stack_a = malloc(sizeof(t_stack));
	stack_b = NULL;
	stack_at = malloc(sizeof(t_stack));
	medium->no = 0;
	medium->argc = argc;
	if (argc == 2)
	{
		medium->argc = ft_count_nums(argv) + 1;
		ft_fill_stack_string(stack_a, argv, medium);
		ft_fill_stack_string(stack_at, argv, medium);
	}
	else
	{
		medium->argc = argc;
		ft_fill_stack(stack_a, argc, argv, medium);
		ft_fill_stack(stack_at, argc, argv, medium);
	}
	ft_check_run(stack_a, stack_b, medium, stack_at);
	return (0);
}
