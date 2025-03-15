/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:18:02 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/22 13:39:00 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_n(const char *src, int *size)
{
	int			i;
	char		*new;

	if (!src || !src[0])
		return (NULL);
	new = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
	{
		free (new);
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
		if (src[i - 1] == '\n')
			break ;
	}
	new[i] = '\0';
	*size = i;
	return (new);
}

int	ft_strchr_gnl(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (-1);
}
