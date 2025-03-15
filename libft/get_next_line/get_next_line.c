/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:17:51 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/25 04:10:06 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *tmp)
{
	char	*line;
	int		i;
	int		j;

	line = ft_strdup_n(tmp, &i);
	j = 0;
	while (tmp[i])
		tmp[j++] = tmp[i++];
	tmp[j] = '\0';
	return (line);
}

int	ft_read(int fd, char **tmp)
{
	char		*new_tmp;
	int			what_is_read;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	buffer[0] = 0;
	while (ft_strchr_gnl(buffer, '\n') == -1)
	{
		what_is_read = read(fd, buffer, BUFFER_SIZE);
		if (what_is_read == -1)
			return (free(buffer), what_is_read);
		buffer[what_is_read] = '\0';
		if (what_is_read == 0)
			break ;
		new_tmp = ft_strjoin(*tmp, buffer);
		free(*tmp);
		if (!new_tmp)
			return (free(buffer), what_is_read);
		*tmp = new_tmp;
	}
	free(buffer);
	return (what_is_read);
}

char	*get_next_line(int fd)
{
	static char	*tmp[1000];
	int			what_is_read;

	if (tmp[fd] && ft_strchr_gnl(tmp[fd], '\n') == 1)
		return (ft_line(tmp[fd]));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	what_is_read = ft_read(fd, tmp + fd);
	if (!tmp[fd] || ((what_is_read == 0) && !tmp[fd][0]))
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	return (ft_line(tmp[fd]));
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("gnlTester/files/nl", O_RDONLY);
// 	line = "";
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("'%s'", line);
// 		free(line);
// 	}
// 	close(fd);
// }