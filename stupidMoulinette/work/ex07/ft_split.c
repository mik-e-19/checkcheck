/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:17:37 by mloh              #+#    #+#             */
/*   Updated: 2021/03/06 16:13:17 by mloh             ###   ########.fr       */
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
	int num_words;
	int i;

	word = 0;
	num_words = 0;
	i = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i], whites) && word == 0)
		{
			++num_words;
			word = 1;
		}
		else if (is_whitespace(str[i], whites))
		{
			word = 0;
		}
		++i;
	}
	return (num_words);
}

int		calc_len(char *str, char *whites)
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
	if (i < n && src[i])
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
	char	**arr;
	int		word;
	int		i;
	int		len;

	arr = (char **)malloc(count_words(str, charset) * sizeof(char *) + 1);
	word = 0;
	g_n_words = 0;
	i = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i], charset) && word == 0)
		{
			word = 1;
			len = calc_len(&str[i], charset);
			arr[g_n_words] = (char *)malloc((len) * sizeof(char));
			arr[g_n_words] = ft_strncpy(arr[g_n_words], &str[i], len);
			++g_n_words;
		}
		else if (is_whitespace(str[i], charset))
			word = 0;
		++i;
	}
	arr[g_n_words] = 0;
	return (arr);
}
