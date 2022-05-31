#include <unistd.h>

int	check_d(char *str, char c, int loc)
{
	int i;

	i = 0;
	while (i < loc)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int	i;
	int	j;
	
	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			j = 0;
			while (argv[2][j] != '\0')
			{
				if (argv[1][i] == argv[2][j])
				{
					if (check_d(argv[1], argv[1][i], i))
					{
						write(1, &argv[1][i], 1);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
