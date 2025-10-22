#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&stack_a, argv + 1);
	if (!stack_is_sorted(stack_a))
	{
		if (stack_length(stack_a) == 2)
			sa(&stack_a, true);
		else if (stack_length(stack_a) == 3)
			sort_three_stack(&stack_a);
		else
			sort_stacks_turk(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
}
