/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:53:13 by tmorais-          #+#    #+#             */
/*   Updated: 2025/10/23 13:53:15 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_stack(t_stack **stack_a)
{
	t_stack	*big;

	big = find_maximum(*stack_a);
	if (big == *stack_a)
		ra(stack_a, true);
	else if ((*stack_a)->next == big)
		rra(stack_a, true);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, true);
}
