/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:52:08 by tmorais-          #+#    #+#             */
/*   Updated: 2025/10/23 13:52:10 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_push(t_stack **stack, t_stack *node_to_top, char stack_name)
{
	while (*stack != node_to_top)
	{
		if (stack_name == 'a')
		{
			if (node_to_top->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (node_to_top->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}
