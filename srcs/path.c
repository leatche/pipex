/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:04:52 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/17 15:29:05 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_path(char **env)
{
	char	**path;
	int		i;

	if (!env)
		error ("no env", 1);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	path = ft_split(env[i] + 5, ':');
	return (path);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*dest;
	char	**path;
	char	*tmp;

	i = 0;
	path = ft_path(env);
	tmp = ft_strjoin("/", cmd);
	while (path && path[i])
	{
		dest = ft_strjoin(path[i], tmp);
		if (access(dest, F_OK | X_OK) == 0)
		{
			free(tmp);
			ft_free_tab(path);
			return (dest);
		}
		free(dest);
		i++;
	}
	ft_free_tab(path);
	free(tmp);
	return (NULL);
}

void	error(char *s, int x)
{
	write(2, s, ft_strlen(s));
	exit(x);
}
