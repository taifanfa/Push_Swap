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
