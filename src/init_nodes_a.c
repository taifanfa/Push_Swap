#include "push_swap.h"
#include <limits.h>

static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*cur_b;
	t_stack	*target;
	long	closest;

	while (stack_a)
	{
		closest = LONG_MIN;
		cur_b = stack_b;
		while (cur_b)
		{
			if (cur_b->value < stack_a->value
				&& cur_b->value > closest)
			{
				closest = cur_b->value;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (closest == LONG_MIN)
			stack_a->target_node = find_maximum(stack_b);
		else
			stack_a->target_node = target;
		stack_a = stack_a->next;
	}
}

static void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	total_a;
	int	total_b;

	total_a = stack_length(a);
	total_b = stack_length(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = total_a - a->index;
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += total_b - a->target_node->index;
		a = a->next;
	}
}

static void	set_cheapest(t_stack *stack)
{
	long	lowest;
	t_stack	*cheapest;

	if (!stack)
		return ;
	lowest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < lowest)
		{
			lowest = stack->push_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = true;
}

void	current_index(t_stack *stack)
{
	int	pos;
	int	median;

	if (!stack)
		return ;
	pos = 0;
	median = stack_length(stack) / 2;
	while (stack)
	{
		stack->index = pos;
		stack->above_median = (pos <= median);
		stack = stack->next;
		++pos;
	}
}

void	init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
