#include <stdlib.h>

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		*ft_rrange(int start, int end)
{
	int i;
	int *arr;

	i = 0;
	arr = (int*)malloc(sizeof(int) * ft_abs(end - start) + 1);
	while (start < end)
	{
		tab[i] = end;
		end--;
		i++;
	}
	tab[i] = end;
	while (start > end)
	{
		tab[i] = end;
		end++;
		i++;
	}
	tab[i] = end;
	return (arr);
}
