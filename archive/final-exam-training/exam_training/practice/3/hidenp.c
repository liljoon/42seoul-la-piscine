#include <unistd.h>

int		main(int argc, char *argv[])
{
	int i;
	int j;
	int cnt;

	i = 0;
	j = 0;
	count = 0;
	if (ac == 3)
	{
		while (av[1][i] != '\0')
		{
			while (av[2][j] != '\0')
			{
				if (av[1][i] == av[2][j])
				{
					cnt++;
					break ;
				}
				j++;
			}
			i++;
		}
		if (av[1][cnt] == '\0')
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
