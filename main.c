/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:44:56 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/10 16:34:10 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_fill_stack(t_stack *stack, int argc, char **argv, t_medium *medium)
{
	int	i;

	i = 0;
	while (argv[++i] != NULL)
	{
		if (argv[i] && i < argc)
		{
			stack->num = ft_atoi(argv[i], medium);
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
	if (medium->no == 0)
	{
		if (ft_repeat(stack_a) == 1)
		{
			free(medium);
			ft_clean_stack(stack_a);
		}
		ft_logic(&stack_a, &stack_b, argc - 1, &stack_at);
		free(medium);
	}
	else
		write(1, "Error\n", 6);
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
	medium->sign = 1;
	medium->argc = argc;
	ft_fill_stack(stack_a, argc, argv, medium);
	ft_fill_stack(stack_at, argc, argv, medium);
	ft_check_run(stack_a, stack_b, medium, stack_at);
	return (0);
}
