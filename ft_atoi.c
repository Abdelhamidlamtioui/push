#include "sort.h"

long	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned long	f;

	f = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		f = f * 10 + nptr[i] - 48;
		if (f > (long)INT_MAX + 1)
			return ((long)INT_MAX + 10);
		i++;
	}
	return (f * sign);
}
