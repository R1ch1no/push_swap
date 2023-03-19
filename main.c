/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:44:56 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/19 14:06:49 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arg_count(char **argv)
{
	int	i;
	int	j;
	int	arg;

	j = 0;
	arg = 0;
	while (argv[++j] != NULL)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			while (((argv[j][i] == ' ') || (argv[j][i] > 8 && argv[j][i] < 14))
				&& (argv[j][i] != '\0'))
				i++;
			if (!(((argv[j][i] == ' ') || (argv[j][i] > 8 && argv[j][i] < 14)))
				&& (argv[j][i] != '\0'))
				arg++;
			while (!(((argv[j][i] == ' ') || (argv[j][i] > 8
					&& argv[j][i] < 14))) && (argv[j][i] != '\0'))
				i++;
		}
	}
	return (arg);
}

int	ft_more_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		while (((arg[i] == ' ') || (arg[i] > 8 && arg[i] < 14))
			&& (arg[i] != '\0'))
			i++;
		if (arg[i] == '\0')
			return (0);
		if (arg[i] != '\0')
			return (1);
	}
	return (1);
}

void	ft_fill_stack_string(t_stack *stack, char **argv, t_medium *medium)
{
	int	i;
	int	j;

	j = 0;
	while (argv[++j] != NULL)
	{
		i = 0;
		while (argv[j][i] && ft_more_arg(&argv[j][i]) == 1)
		{
			while (((argv[j][i] == ' ') || (argv[j][i] > 8 && argv[j][i] < 14))
				&& (argv[j][i] != '\0'))
				i++;
			stack->num = ft_atoi(&argv[j][i], medium);
			medium->nums++;
			while (!(((argv[j][i] == ' ') || (argv[j][i] > 8
					&& argv[j][i] < 14))) && (argv[j][i] != '\0'))
				i++;
			if (medium->nums < (medium->argc))
			{
				stack->next = malloc(sizeof(t_stack));
				stack = stack->next;
			}
		}
		stack->next = NULL;
	}
}

void	ft_check_run(t_stack *stack_a, t_stack *stack_b, t_medium *medium,
		t_stack *stack_at)
{
	if (medium->no == 1 || ft_repeat(stack_a) == 1)
	{
		write(1, "Error\n", 6);
		ft_clean_stack(stack_a);
		ft_clean_stack(stack_at);
		free(medium);
		return ;
	}
	if (ft_sorted(stack_a) == 1)
	{
		if (medium->argc == 3 && medium->no == 0)
			ft_sort_three(&stack_a, &stack_b);
		else if (medium->argc == 5 || medium->argc == 4)
			ft_sort_five(&stack_a, &stack_b, medium);
		else
			ft_logic(&stack_a, &stack_b, medium->argc, &stack_at);
	}
	ft_clean_stack(stack_a);
	ft_clean_stack(stack_at);
	free(medium);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*stack_at;
	t_medium	*medium;

	if (argc < 2 || ft_arg_count(argv) <= 1)
		return (0);
	medium = malloc(sizeof(t_medium));
	stack_a = malloc(sizeof(t_stack));
	stack_b = NULL;
	stack_at = malloc(sizeof(t_stack));
	medium->argc = ft_arg_count(argv);
	medium->no = 0;
	medium->nums = 0;
	ft_fill_stack_string(stack_a, argv, medium);
	medium->nums = 0;
	ft_fill_stack_string(stack_at, argv, medium);
	ft_check_run(stack_a, stack_b, medium, stack_at);
	return (0);
}
