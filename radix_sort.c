#include "sort.h"

static int	find_bits_max(t_stack *max)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = max->rank;
	while (max->rank != 0)
	{		
		max->rank = max->rank >> 1;
		i++;
	}
	max->rank = tmp;
	return (i);
}

void	sort(t_stack **s_a, t_stack **s_b, t_stack *max)
{
	int	l;
	int	i;
	int	j;
	int	b;

	j = 0;
	l = stack_size(*s_a);
	b = find_bits_max(max);
	while (j < b)
	{
		i = 0;
		while (i < l)
		{
			if ((((*s_a)->rank >> j) & 1) == 0)
				pb(s_b, s_a);
			else
				ra(s_a);
			i++;
		}
		while (*s_b)
			pa(s_a, s_b);
		j++;
	}
}
