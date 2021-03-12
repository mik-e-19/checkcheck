#include <stdlib.h>

int		whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		len(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		while (*str && whitespace(*str))
			str++;
		if (*str && !whitespace(*str))
		{
			i++;
			while (*str && !whitespace(*str))
				str++;
		}
	}
	return (i);
}

char	*word_size(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !whitespace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !whitespace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * (len(str) + 1));
	while (*str)
	{
		while (*str && whitespace(*str))
			str++;
		if (*str && !whitespace(*str))
		{
			array[i] = word_size(str);
			i++;
			while (*str && !whitespace(*str))
				str++;
		}
	}
	array[i] = NULL;
	return (array);
}
