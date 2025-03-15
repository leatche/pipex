/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:08:37 by tcherepoff        #+#    #+#             */
/*   Updated: 2024/11/17 22:55:22 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size_dst;

	i = 0;
	j = ft_strlen(dst);
	size_dst = ft_strlen(dst);
	if (size_dst >= dstsize)
		return (dstsize + ft_strlen(src));
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && j < dstsize - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (ft_strlen(src) + size_dst);
}
