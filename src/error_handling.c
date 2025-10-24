/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:50:17 by tmorais-          #+#    #+#             */
/*   Updated: 2025/10/23 13:50:19 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

bool	error_digit(char *str_number)
{
	int	i;

	i = 0;
	if (str_number[i] == '-' || str_number[i] == '+')
		i++;
	if (!str_number[i])
		return (true);
	while (str_number[i])
	{
		if (!ft_isdigit(str_number[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	error_duplicate(t_stack *stack, int number_to_check)
{
	while (stack)
	{
		if (stack->value == number_to_check)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	free_stack(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	cur = *stack;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*stack = NULL;
}

void	free_error(t_stack **stack_a)
{
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}
