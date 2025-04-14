#include "sort.h"

static void	ft_rotate(t_stack **top)
{
	t_stack	*tmp;
	t_stack	*new_top;

	if ((*top) == NULL || (*top)->next == NULL)
		return ;
	tmp = *top;
	new_top = tmp->next;
	while (*top != NULL)
	{
		if ((*top)->next == NULL)
		{
			tmp->next = NULL;
			(*top)->next = tmp;
			*top = new_top;
			return ;
		}
		(*top) = (*top)->next;
	}
}

void	ra(t_stack **s_a)
{
	ft_rotate(s_a);
	write (1, "ra\n", 3);
}

void	rb(t_stack **s_b)
{
	ft_rotate(s_b);
	write (1, "rb\n", 3);
}

void	rr(t_stack **s_a, t_stack **s_b)
{
	ft_rotate(s_a);
	ft_rotate(s_b);
	write (1, "rr\n", 3);
}
