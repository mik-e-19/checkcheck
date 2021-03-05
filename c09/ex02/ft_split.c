/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:17:37 by mloh              #+#    #+#             */
/*   Updated: 2021/03/05 23:03:53 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		g_n_words;

int		is_whitespace(char c, char *whites)
{
	int i;

	i = 0;
	while (whites[i])
	{
		if (whites[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int		count_words(char *str, char *whites)
{
	int	word;
	int number_words;
	int i;

	word = 0;
	number_words = 0;
	i = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i], whites) && word == 0)
		{
			++number_words;
			word = 1;
		}
		else if (is_whitespace(str[i], whites))
		{
			word = 0;
		}
		++i;
	}
	return (number_words);
}

int		calculate_length(char *str, char *whites)
{
	int i;

	i = 0;
	while (str[i] && !is_whitespace(str[i], whites))
		++i;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i])
		{
			dest[i] = '\0';
			++i;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		word;
	int		i;
	int		length;

	array = (char **)malloc(count_words(str, charset) * sizeof(char *) + 1);
	word = 0;
	g_n_words = 0;
	i = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i], charset) && word == 0)
		{
			word = 1;
			length = calculate_length(&str[i], charset);
			array[g_n_words] = (char *)malloc((length) * sizeof(char));
			array[g_n_words] = ft_strncpy(array[g_n_words], &str[i], length);
			++g_n_words;
		}
		else if (is_whitespace(str[i], charset))
			word = 0;
		++i;
	}
	array[g_n_words] = 0;
	return (array);
}
