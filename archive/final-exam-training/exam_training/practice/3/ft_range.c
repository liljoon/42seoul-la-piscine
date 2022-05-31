#include <stdlib.h>

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int *ft_range(int start, int end)
{
	int	i;
	int *arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * ft_abs(end - start) + 1);
    while (start < end)
    {
        array[i] = start;
        start++;
        ++i;
    }
	arr[i] = start;
	while (start > end)
	{
		arr[i] = start;
		start--;
		i++;
	}
	arr[i] = start;
    return (array);
}
