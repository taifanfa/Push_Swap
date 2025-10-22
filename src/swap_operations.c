#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*f;
	t_stack	*s;

	if (!*stack || !(*stack)->next)
		return ;
	f = *stack;
	s = f->next;
	f->next = s->next;
	if (s->next)
		s->next->prev = f;
	s->prev = NULL;
	s->next = f;
	f->prev = s;
	*stack = s;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}
