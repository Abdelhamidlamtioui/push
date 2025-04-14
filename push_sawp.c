#include "sort.h"

int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;
	t_stack	*max;

	max = NULL;
	s_a = NULL;
	if (ac == 1)
		return (0);
	s_b = NULL;
	s_a = ft_init_stack(av, (ac - 1));
	if (ft_sorted(s_a) == 0)
		return (ft_free_list(s_a), 0);
	if (stack_size(s_a) == 2 && s_a->data > s_a->next->data)
		sa(&s_a);
	else if (stack_size(s_a) <= 20)
		sort_20(&s_a, &s_b);
	else
	{
		find_rank(s_a);
		max = ft_find_max(s_a);
		sort(&s_a, &s_b, max);
	}
	ft_free_list(s_a);
}
