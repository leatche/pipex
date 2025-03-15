/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:15:28 by ltcherep          #+#    #+#             */
/*   Updated: 2024/11/06 17:54:24 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	int	i;

	if (!d || !s)
		return (NULL);
	if (s < d)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(d + i) = *(char *)(s + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(d + i) = *(char *)(s + i);
			i++;
		}
	}
	return (d);
}
