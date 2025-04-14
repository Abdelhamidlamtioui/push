#include "sort.h"

t_stack	*ft_find_min(t_stack *s_a)
{
	t_stack	*min;

	if (!s_a)
		return (NULL);
	min = s_a;
	while (s_a)
	{
		if (min->data > s_a->data)
			min = s_a;
		s_a = s_a->next;
	}
	return (min);
}

void	find_rank(t_stack *s_a)
{
	t_stack	*top;
	t_stack	*current;

	if (!s_a)
		return ;
	top = s_a;
	while (s_a != NULL)
	{
		current = top;
		while (current != NULL)
		{
			if (s_a->data > current->data)
			{
				s_a->rank++;
			}
			current = current->next;
		}
		s_a = s_a->next;
	}
}

t_stack	*ft_find_max(t_stack *s_a)
{
	t_stack	*max;

	max = s_a;
	while (s_a)
	{
		if (max->rank < s_a->rank)
			max = s_a;
		s_a = s_a->next;
	}
	return (max);
}

void	position(t_stack *top)
{
	int	i;
	int	mid;

	if (!top)
		return ;
	mid = stack_size(top) / 2;
	i = 0;
	while (top != NULL)
	{
		top->position = i;
		if (top->position <= mid)
			top->rotate = 1;
		else
		{
			top->rotate = 0;
		}
		i++;
		top = top->next;
	}
}

void	ft_free_list(t_stack *s_a)
{
	t_stack	*tmp;

	while (s_a)
	{
		tmp = s_a->next;
		free(s_a);
		s_a = tmp;
	}
}
