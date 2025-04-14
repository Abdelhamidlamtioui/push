#include "sort.h"

int	ft_sorted(t_stack *s_a)
{
	t_stack	*curr;

	while (s_a != NULL)
	{
		curr = s_a->next;
		while (curr)
		{
			if (curr->data < s_a->data)
				return (-1);
			curr = curr->next;
		}
		s_a = s_a->next;
	}
	return (0);
}
