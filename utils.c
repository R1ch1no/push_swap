/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:19:18 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/10 16:42:57 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_medium *medium)
{
	unsigned int	i;
	long			result;
	int				sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (str[i] > '9' || str[i] < '0')
			medium->no = 1;
		result = (result * 10) + (str[i++] - '0');
		if (result * sign > 2147483647)
			return (-1);
		if (result * sign < -2147483648)
			return (0);
	}
	return (result * sign);
}

int	ft_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next != NULL)
	{
		if (current->num > current->next->num)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_repeat(t_stack *stack)
{
	t_stack		*current;
	t_stack		*start;
	long long	cn;

	current = stack;
	start = stack;
	cn = start->num;
	while (start->next)
	{
		while (current->next != NULL)
		{
			current = current->next;
			if (cn == current->num)
			{
				write(1, "Repeating numbers\n", 18);
				return (1);
			}
		}
		if (start->next != NULL)
			start = start->next;
		current = start;
		cn = start->num;
	}
	return (0);
}

void	ft_clean_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*start;

	current = stack;
	start = stack;
	if (stack == NULL)
		exit(0);
	while (start->next)
	{
		while (current->next->next)
		{
			current = current->next;
		}
		free(current->next);
		current->next = NULL;
		current = start;
	}
	free(stack);
}

long long	ft_last_node(t_stack *stack)
{
	t_stack		*current;
	long long	num;

	current = stack;
	while (current->next != NULL)
		current = current->next;
	num = current->num;
	return (num);
}
