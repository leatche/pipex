/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:08:48 by tcherepoff        #+#    #+#             */
/*   Updated: 2024/11/09 19:28:12 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*l;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	l = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!l)
		return (NULL);
	while (i < ft_strlen(s))
	{
		l[i] = (*f)(i, s[i]);
		i++;
	}
	l[i] = '\0';
	return (l);
}
