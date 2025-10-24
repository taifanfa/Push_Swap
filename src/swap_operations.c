/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:54:00 by tmorais-          #+#    #+#             */
/*   Updated: 2025/10/23 13:54:02 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
