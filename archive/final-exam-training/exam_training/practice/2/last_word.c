#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;
	char *last;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] <= ' ' && argv[1][i + 1] > ' ')
				last = &argv[1][i + 1];
			i++;
		}
		i = 0;
		while (last && last[i] > ' ')
		{
			write(1, &last[i], 1);
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
