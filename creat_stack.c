#include "sort.h"

static t_stack	*ft_creat_node(int value)
{
	t_stack	*top;

	top = (t_stack *)malloc(sizeof(t_stack));
	if (top == NULL)
		return (NULL);
	top->data = value;
	top->next = NULL;
	top->rank = 1;
	top->rotate = 0;
	top->position = 0;
	return (top);
}

static int	check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static t_stack	*add_new(char **str, t_stack *top)
{
	t_stack	*tmp;
	long	a;
	int		j;

	tmp = NULL;
	j = count_str(str) - 1;
	while (j >= 0)
	{
		a = ft_atoi(str[j]);
		if (a > INT_MAX)
		{
			write(2, "Error\n", 6);
			return (ft_free_list(top), ft_free(str), NULL);
		}
		tmp = top;
		top = ft_creat_node(a);
		if (top == NULL)
			return (ft_free_list(tmp), ft_free(str), NULL);
		if (check_rep(top, tmp) == -1)
			return (free(top), ft_free_list(tmp), ft_free(str), NULL);
		top->next = tmp;
		j--;
	}
	return (top);
}

t_stack	*ft_creat_stack(char **av, int i)
{
	t_stack	*top;
	char	**str;

	top = NULL;
	while (i > 0)
	{
		if (av[i][0] == '\0' || check_string(av[i]) == 0)
		{
			write(2, "Error\n", 6);
			return (ft_free_list(top), NULL);
		}
		str = check_input(av[i]);
		if (str == NULL)
			return (ft_free_list(top), NULL);
		top = add_new(str, top);
		if (top == NULL)
			return (ft_free_list(top), NULL);
		ft_free(str);
		i--;
	}
	return (top);
}
