#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* Entry */
void	push_swap(int argc, char **argv);

/* Stack Initialization */
void	init_stack_a(t_stack **a, char **argv);

/* Node Initialization */
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);

/* Sorting */
void	sort_stacks_turk(t_stack **a, t_stack **b);
void	sort_three_stack(t_stack **a);

/* Stack Operations */
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

/* Stack Utils */
int		stack_length(t_stack *stack);
bool	stack_is_sorted(t_stack *stack);
t_stack	*find_last_node(t_stack *stack);
t_stack	*find_minimum(t_stack *stack);
t_stack	*find_maximum(t_stack *stack);
t_stack	*get_cheapest_node(t_stack *stack);

/* Preparation */
void	prep_push(t_stack **stack, t_stack *top, char name);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	minimum_to_top(t_stack **a);

/* Error Handling */
bool	error_digit(char *str);
bool	error_duplicate(t_stack *a, int num);
void	free_stack(t_stack **stack);
void	free_error(t_stack **a);

/* String Utils */
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* Printf */
int		ft_printf(const char *format, ...);

#endif
