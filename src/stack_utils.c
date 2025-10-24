/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:53:41 by tmorais-          #+#    #+#             */
/*   Updated: 2025/10/23 13:53:43 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	stack_length(t_stack *stack)
{
	int	total;

	total = 0;
	while (stack)
	{
		total++;
		stack = stack->next;
	}
	return (total);
}

t_stack	*find_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*find_minimum(t_stack *stack)
{
	long	small;
	t_stack	*min;

	if (!stack)
		return (NULL);
	small = LONG_MAX;
	while (stack)
	{
		if (stack->value < small)
		{
			small = stack->value;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

t_stack	*find_maximum(t_stack *stack)
{
	long	big;
	t_stack	*max;

	if (!stack)
		return (NULL);
	big = LONG_MIN;
	while (stack)
	{
		if (stack->value > big)
		{
			big = stack->value;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}
