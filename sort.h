#ifndef SORT_H
# define SORT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack		*next;
	int					rotate;
	int					data;
	int					rank;
	int					position;
}	t_stack;

// check input
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *nptr);
char	**check_input(char *str);
int		check_rep(t_stack *top, t_stack *tmp);
int		count_str(char **s);
int		ft_sorted(t_stack *s_a);
//free
void	ft_free_list(t_stack *s_a);
void	ft_free(char **p);
//creat t_stack
t_stack	*ft_creat_stack(char **av, int ac);
//operation
void	rra(t_stack **s_a);
void	rrb(t_stack **s_b);
void	rrr(t_stack **s_a, t_stack **s_b);
void	ra(t_stack **s_a);
void	rb(t_stack **s_b);
void	rr(t_stack **s_a, t_stack **s_b);
void	sa(t_stack **top);
void	sb(t_stack **top);
void	ss(t_stack **s_a, t_stack **s_b);
void	pa(t_stack **top_a, t_stack **top_b);
void	pb(t_stack **top_b, t_stack **top_a);
//algo
void	ft_sort_3(t_stack **top);
void	sort(t_stack **s_a, t_stack **s_b, t_stack *max);
void	sort_20(t_stack **s_a, t_stack **s_b);
void	find_rank(t_stack *s_a);
// utill fct
int		stack_size(t_stack *top);
t_stack	*find_min(t_stack *s_a);
void	position(t_stack *s_a);
t_stack	*find_maxx(t_stack *s_a);

#endif
