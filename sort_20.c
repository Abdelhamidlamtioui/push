#include "sort.h"

void	sort_20(t_stack **s_a, t_stack **s_b)
{
	t_stack	*min;
	int		mid;
	int		size;

	size = stack_size(*s_a);
	while (size > 3)
	{
		position(*s_a);
		min = find_min(*s_a);
		mid = stack_size(*s_a) / 2;
		if (min->position == 0)
			pb(s_b, s_a);
		else if (min->position <= mid)
			ra(s_a);
		else if (min->position > mid)
			rra(s_a);
		size = stack_size(*s_a);
	}
	if (stack_size(*s_a) == 3)
		ft_sort_3(s_a);
	while (*s_b)
		pa(s_a, s_b);
}
