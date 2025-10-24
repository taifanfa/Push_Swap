/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:09:04 by tmorais-          #+#    #+#             */
/*   Updated: 2025/10/24 18:08:36 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	handle_sorting(t_stack **a, t_stack **b)
{
	if (stack_length(*a) == 2)
		sa(a, true);
	else if (stack_length(*a) == 3)
		sort_three_stack(a);
	else
		sort_stacks_turk(a, b);
}

void	push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	char	**split_free;
	bool	need_free;

	a = NULL;
	b = NULL;
	need_free = (argc == 2);
	split_free = NULL;
	if (need_free)
	{
		args = ft_split(argv[1], ' ');
		split_free = args;
	}
	else
		args = argv + 1;
	if (!args || (need_free && !args[0]))
		return ;
	init_stack_a(&a, args, split_free);
	if (!stack_is_sorted(a))
		handle_sorting(&a, &b);
	free_stack(&a);
	if (need_free)
		free_split(args);
}
