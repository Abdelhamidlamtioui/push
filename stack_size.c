#include "sort.h"

int	stack_size(t_stack *top)
{
	int	i;

	if (top == NULL)
		return (0);
	i = 0;
	while (top != NULL)
	{
		i++;
		top = top->next;
	}
	return (i);
}
