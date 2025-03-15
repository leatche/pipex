/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:33:10 by ltcherep          #+#    #+#             */
/*   Updated: 2024/11/16 17:33:24 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static char	**ft_alloc(char **tab, char const *s, char c, size_t count)
{
	size_t	j;
	size_t	k;
	size_t	word;

	word = 0;
	j = 0;
	while (word < count)
	{
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			j++;
			k++;
		}
		tab[word] = ft_calloc(k + 1, sizeof(char));
		if (!tab)
			return (NULL);
		word++;
	}
	return (tab);
}

static char	**ft_fill(char **tab, char const *s, char c, size_t count)
{
	size_t	j;
	size_t	k;
	size_t	word;

	word = 0;
	j = 0;
	while (word < count)
	{
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			tab[word][k] = s[j];
			j++;
			k++;
		}
		word++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	count;

	if (!s)
		return (NULL);
	tab = ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	count = ft_count(s, c);
	tab = ft_alloc(tab, s, c, count);
	tab = ft_fill(tab, s, c, count);
	return (tab);
}
