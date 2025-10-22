#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	top = *stack;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = top;
	last->prev = NULL;
	top->prev = last;
	*stack = last;
}

void	rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_printf("rrr\n");
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, true);
	current_index(*a);
	current_index(*b);
}
