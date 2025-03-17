/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:47:33 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/17 15:06:07 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

int		ft_executate_command(char *av, char **env);
int		ft_child(char **av, char **env, int pipe_fd[]);
int		ft_parent(char **av, char **env, int pipe_fd[], int pid);
int		pipex(char **av, char **env);

char	**ft_path(char **env);
char	*get_path(char *cmd, char **env);
void	error(char *s, int x);

#endif