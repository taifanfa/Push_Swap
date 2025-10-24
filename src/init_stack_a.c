/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:51:51 by tmorais-          #+#    #+#             */
/*   Updated: 2025/10/24 16:48:03 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

static void	add_node(t_stack **stack, int number)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = number;
	new_node->cheapest = false;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = find_last_node(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

static void	handle_error(t_stack **stack_a, char **split_to_free)
{
	free_stack(stack_a);
	if (split_to_free)
		free_split(split_to_free);
	write(2, "Error\n", 6);
	exit(1);
}

void	init_stack_a(t_stack **stack_a, char **argv, char **split_to_free)
{
	long	num;
	int		i;

	if (!argv || !argv[0])
		return ;
	i = 0;
	while (argv[i])
	{
		if (error_digit(argv[i]))
			handle_error(stack_a, split_to_free);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			handle_error(stack_a, split_to_free);
		if (error_duplicate(*stack_a, (int)num))
			handle_error(stack_a, split_to_free);
		add_node(stack_a, (int)num);
		i++;
	}
}
