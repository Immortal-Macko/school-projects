#include "libft.h"

static size_t	ft_lttrs(const char *s, size_t *i, char c)
{
	size_t l;
	size_t m;

	l = 0;
	m = *i;
	if (s[m] == c)
	{
		while (s[m] == c)
			m++;
	}
	while (s[m] != c && s[m] != '\0')
	{
		m++;
		l++;
	}
	*i = m;
	return (l);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t i;
	size_t w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			w++;
		}
	}
	return (w);
}

static char		*ft_fill_str(const char *s, char c, size_t *k, char *str)
{
	size_t q;
	size_t m;
	size_t l;

	m = *k;
	l = ft_lttrs(s, k, c);
	q = 0;
	while (q < l)
	{
		while (s[m] == c)
			m++;
		if (s[m] != c && s[m] != '\0')
			str[q] = s[m];
		m++;
		q++;
	}
	str[q] = '\0';
	return (str);
}

static char		**ft_mem_alloc(char const *s, char c, size_t n, char **str)
{
	int		i;
	size_t	ind;
	size_t	k;

	i = -1;
	ind = 0;
	k = 0;
	while (++i < (int)n)
	{
		str[i] = (char *)malloc(sizeof(char) * (ft_lttrs(s, &ind, c) + 1));
		if (str[i] != NULL)
			str[i] = ft_fill_str(s, c, &k, str[i]);
		else
		{
			while (--i > -1)
			{
				free(str[i]);
				str[i] = NULL;
			}
			free(str);
			str = NULL;
			return (str);
		}
	}
	return (str);
}

char			**ft_split(char const *s, char c)
{
	size_t	n;
	char	**str;

	if (s == NULL)
		return (NULL);
	n = ft_count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (str == NULL)
		return (NULL);
	str[n] = NULL;
	if (n == 0)
		return (str);
	str = ft_mem_alloc(s, c, n, str);
	return (str);
}
