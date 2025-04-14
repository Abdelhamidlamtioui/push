#include "sort.h"

static void	ft_swap(t_stack **top)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if ((*top) == NULL || (*top)->next == NULL)
		return ;
	tmp1 = *top;
	tmp2 = (*top)->next->next;
	*top = (*top)->next;
	(*top)->next = tmp1;
	(*top)->next->next = tmp2;
}

void	sa(t_stack **top)
{
	ft_swap(top);
	write (1, "sa\n", 3);
}

void	sb(t_stack **top)
{
	ft_swap(top);
	write (1, "sb\n", 3);
}

void	ss(t_stack **s_a, t_stack **s_b)
{
	ft_swap(s_a);
	ft_swap(s_b);
	write (1, "ss\n", 3);
}
