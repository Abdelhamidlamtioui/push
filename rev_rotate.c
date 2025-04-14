#include "sort.h"

static void	ft_rev_rotate(t_stack **top)
{
	t_stack	*tmp;
	t_stack	*new_top;

	if ((*top) == NULL || (*top)->next == NULL)
		return ;
	tmp = *top;
	while (*top != NULL)
	{
		if ((*top)->next->next == NULL)
		{
			new_top = (*top)->next;
			(*top)->next->next = tmp;
			(*top)->next = NULL;
			*top = new_top;
			return ;
		}
		(*top) = (*top)->next;
	}
}

void	rra(t_stack **s_a)
{
	ft_rev_rotate(s_a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **s_b)
{
	ft_rev_rotate(s_b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **s_a, t_stack **s_b)
{
	ft_rev_rotate(s_a);
	ft_rev_rotate(s_b);
	write (1, "rrr\n", 4);
}
