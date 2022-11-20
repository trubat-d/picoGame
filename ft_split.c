#include "inc/PicoShell.h"

unsigned	word_count(char *s, char c)
{
	unsigned	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char *add_word(char *s, char c)
{
	unsigned i = 0;
	char *ret;
	while (s[i] && s[i] != c)
		i++;
	ret = malloc((i + 1) * sizeof(char));
	i = 0;
	while (s[i] && s[i] != c)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	**ft_split(char *s, char c)
{
	if (s && !*s)
	{
		free(s);
		s = NULL;
	}
	if (!s)
		return (NULL);
	unsigned	i = 0;
	char		*tmp = s;
	char **ss = malloc((word_count(s, c) + 1) * sizeof(char *));
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			ss[i++] = add_word(s, c);
		while (*s && *s != c)
			s++;
	}
	ss[i] = NULL;
	free(tmp);
	return (ss);
}