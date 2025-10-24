/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_turk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:53:03 by tmorais-          #+#    #+#             */
/*   Updated: 2025/10/23 13:53:05 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_from_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest_node(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		reverse_rotate_both(a, b, cheapest);
	prep_push(a, cheapest, 'a');
	prep_push(b, cheapest->target_node, 'b');
	pb(b, a, true);
}

static void	push_from_b_to_a(t_stack **a, t_stack **b)
{
	prep_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

void	minimum_to_top(t_stack **stack_a)
{
	t_stack	*min;

	min = find_minimum(*stack_a);
	while ((*stack_a)->value != min->value)
	{
		if (min->above_median)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
}

void	sort_stacks_turk(t_stack **stack_a, t_stack **stack_b)
{
	int	remaining;

	remaining = stack_length(*stack_a);
	if (remaining-- > 3 && !stack_is_sorted(*stack_a))
		pb(stack_b, stack_a, true);
	if (remaining-- > 3 && !stack_is_sorted(*stack_a))
		pb(stack_b, stack_a, true);
	while (remaining-- > 3 && !stack_is_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		push_from_a_to_b(stack_a, stack_b);
	}
	sort_three_stack(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		push_from_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	minimum_to_top(stack_a);
}
