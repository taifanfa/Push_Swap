#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

static void	add_node(t_stack **stack, int number)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = number;
	new_node->cheapest = false;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = find_last_node(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	init_stack_a(t_stack **stack_a, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_digit(argv[i]))
			free_error(stack_a);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_error(stack_a);
		if (error_duplicate(*stack_a, (int)num))
			free_error(stack_a);
		add_node(stack_a, (int)num);
		i++;
	}
}

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
