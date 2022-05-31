int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while(str[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}
