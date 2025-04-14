#include "sort.h"

static int	count_row( char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	if (s[i] != c)
		j++;
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	return (j);
}

static char	*ft_cpy(char const *s, char *p, int lstart, int c)
{
	int	i;

	i = 0;
	while (s[lstart] && s[lstart] != c)
	{
		p[i] = s[lstart];
		i++;
		lstart++;
	}
	p[i] = '\0';
	return (p);
}

void	ft_free(char **p)
{
	int	j;

	if (p == NULL)
		return ;
	j = 0;
	while (p[j])
	{
		free(p[j]);
		j++;
	}
	free(p);
}

static char	**ft_s(char const *s, char c, char **p, int row)
{
	int	lstart;
	int	j;
	int	i;

	lstart = 0;
	i = 0;
	while (i < row)
	{
		while (s[lstart] && s[lstart] == c)
			lstart++;
		j = lstart;
		while (s[j] && s[j] != c)
			j++;
		p[i] = (char *)malloc(sizeof(char ) * ((j - lstart) + 1));
		if (p[i] == NULL)
		{
			ft_free(p);
			return (NULL);
		}
		p[i] = ft_cpy(s, p[i], lstart, c);
		lstart = j;
		i++;
	}
	p[i] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		row;
	char	**p;

	if (!s || *s == '\0')
		return (NULL);
	row = count_row(s, c);
	p = (char **)malloc(sizeof(char *) * (row + 1));
	if (p == NULL)
		return (NULL);
	ft_s(s, c, p, row);
	return (p);
}
