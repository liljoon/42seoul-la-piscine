#include <unistd.h>

int	letter_cnt(char c)
{
	int repeat;

	if (c >= 'A' && c <= 'Z')
		repeat = c - 'A' + 1;
	else if (c >= 'a' && c <= 'z')
		repeat = c - 'a' + 1;
	else 
		repeat = 1;
	return (repeat);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	repeat;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			repeat = letter_cnt(argv[1][i]);
			while (repeat--)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
