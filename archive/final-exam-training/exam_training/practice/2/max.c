int	max(int *tab, unsigned int len)
{
	int i;
	int	max_v;

	if(!tab)
		return (0);
	i = 0;
	while (len)
	{
		if (tab[i] > tab [i + 1])
			max_v = tab[i];
		i++;
		len--;
	}
	return (max_v);
}
