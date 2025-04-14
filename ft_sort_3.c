#include "sort.h"

void	ft_sort_3(t_stack **top)
{
	t_stack	*p1;
	t_stack	*p2;
	t_stack	*p3;

	p1 = (*top);
	p2 = (*top)->next;
	p3 = (*top)->next->next;
	if (p1->data > p3->data && p1->data > p2->data)
	{
		ra(top);
		p1 = *top;
		p2 = (*top)->next;
		if (p1->data > p2->data)
			sa(top);
	}
	else if (p1->data > p2->data && p1->data < p3->data)
		sa(top);
	else if (p2->data > p3->data)
	{
		rra(top);
		p1 = *top;
		p2 = (*top)->next;
		if (p1->data > p2->data)
			sa(top);
	}
}
