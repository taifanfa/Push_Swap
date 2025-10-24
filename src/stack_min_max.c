/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:53:21 by tmorais-          #+#    #+#             */
/*   Updated: 2025/10/23 13:53:23 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_minimum(t_stack *stack)
{
	long	small;
	t_stack	*node;

	if (!stack)
		return (NULL);
	small = LONG_MAX;
	while (stack)
	{
		if (stack->value < small)
		{
			small = stack->value;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_stack	*find_maximum(t_stack *stack)
{
	long	big;
	t_stack	*node;

	if (!stack)
		return (NULL);
	big = LONG_MIN;
	while (stack)
	{
		if (stack->value > big)
		{
			big = stack->value;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}
