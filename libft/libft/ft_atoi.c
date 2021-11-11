int	ft_atoi(const char *str)
{
	unsigned int	n;
	unsigned int	j;
	long long		num;

	n = 0;
	j = 0;
	num = 0;
	while (((str[n] > 8 && str[n] < 14) || str[n] == ' ') && str[n] != '\0')
	{
		n++;
	}
	if (str[n] == '-' || str[n] == '+')
	{
		j = str[n];
		n++;
	}
	while ((str[n] > 47) && (str[n] < 58))
	{
		num = num * 10 + (str[n] - 48);
		n++;
	}
	if (j == 45)
		num = -1 * num;
	return ((int)num);
}
