/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:54:12 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 19:49:18 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	if (s[i] != c)
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * count_words(s, c) + 1);
	while (*s)
	{
		if (*s == c)
			s++;
		if (*s && *s != c)
		{
			words[++j] = ft_strnew(word_len(s, c));
			while (*s && *s != c)
				words[j][i++] = *s++;
			i = 0;
		}
	}
	words[j + 1] = NULL;
	return (words);
}
