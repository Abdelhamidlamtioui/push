#include "sort.h"

static char	check_digit(char c)
{
	if (!(c >= '0' && c <= '9'))
	{
		write (2, "Error\n", 6);
		return (0);
	}
	return (c);
}

int	check_rep(t_stack *top, t_stack *tmp)
{
	if (!top || !tmp)
		return (0);
	while (tmp != NULL)
	{
		if (top->data == tmp->data)
		{
			write (2, "Error\n", 6);
			return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	count_str(char **s)
{
	int	i;

	i = 0;
	if (s[i] == NULL)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	**check_input(char *str)
{
	int		i;
	int		j;
	char	**p;

	p = ft_split(str, ' ');
	if (p == NULL)
		return (NULL);
	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			if (p[i][j] == '-' || p[i][j] == '+')
				j++;
			if (check_digit(p[i][j]) == 0)
				return (ft_free(p), NULL);
			if (check_digit(p[i][j]) != 0 && (p[i][j + 1] == '-'
						|| p[i][j + 1] == '+'))
				return (ft_free(p), check_digit(0), NULL);
			j++;
		}
		i++;
	}
	return (p);
}
