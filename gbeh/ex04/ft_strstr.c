/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeh <gbeh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:57:23 by gbeh              #+#    #+#             */
/*   Updated: 2021/02/26 18:54:09 by gbeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_needle(char *hay, char *needle, int needle_size, int pos)
{
	int	idx_needle;

	idx_needle = -1;
	while (++idx_needle < needle_size)
	{
		if (needle[idx_needle] != hay[pos + idx_needle])
			return (idx_needle);
	}
	return (idx_needle);
}

int		ft_strlen(char *s)
{
	int len;

	len = -1;
	while (s[++len] != '\0')
	{
	}
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int			idx_hay;
	int			needle;
	const int	haystack_size = ft_strlen(str);
	const int	needle_size = ft_strlen(to_find);

	idx_hay = -1;
	while (++idx_hay < haystack_size - needle_size)
	{
		needle = find_needle(str, to_find, needle_size, idx_hay);
		if (needle == needle_size)
			return (&(str[idx_hay]));
	}
	return ((needle_size == 0) ? str : 0);
}
