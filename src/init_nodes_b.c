#include "push_swap.h"
#include <limits.h>

static void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*cur_a;
	t_stack	*target;
	long	closest;

	while (stack_b)
	{
		closest = LONG_MAX;
		cur_a = stack_a;
		while (cur_a)
		{
			if (cur_a->value > stack_b->value
				&& cur_a->value < closest)
			{
				closest = cur_a->value;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (closest == LONG_MAX)
			stack_b->target_node = find_minimum(stack_a);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
