#include "sort.h"

static void	ft_push(t_stack **top_to, t_stack **top_from)
{
	t_stack	*tmp;

	if (*top_from == NULL)
		return ;
	tmp = *top_from;
	*top_from = (*top_from)->next;
	tmp->next = *top_to;
	*top_to = tmp;
}

void	pa(t_stack **top_a, t_stack **top_b)
{
	ft_push(top_a, top_b);
	write (1, "pa\n", 3);
}

void	pb(t_stack **top_b, t_stack **top_a)
{
	ft_push(top_b, top_a);
	write (1, "pb\n", 3);
}
