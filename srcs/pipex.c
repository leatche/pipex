/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:23:11 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/17 15:29:24 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_executate_command(char *av, char **env)
{
	char	*command;
	char	*path;
	char	**command_av;

	command = av;
	command_av = ft_split(command, ' ');
	path = get_path(command_av[0], env);
	if (!path)
	{
		ft_free_tab(command_av);
		error("no path", 127);
	}
	free(command_av[0]);
	command_av[0] = path;
	if (execve(path, command_av, env) == -1)
	{
		ft_free_tab(command_av);
		error("not found the command", 127);
	}
	return (1);
}

int	ft_child(char **av, char **env, int pipe_fd[])
{
	int	fdstdint;
	int	fdstdout;
	int	fd_in;
	int	result;

	fdstdint = dup(0);
	fdstdout = dup(1);
	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
		error("can't open fd_in", 1);
	dup2(fd_in, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	result = ft_executate_command(av[2], env);
	dup2(fdstdint, 0);
	dup2(fdstdout, 1);
	if (result == -1)
		return (-1);
	exit(0);
}

int	ft_parent(char **av, char **env, int pipe_fd[], int pid)
{
	int	fdstdint;
	int	fdstdout;
	int	fd_out;
	int	result;
	int	exit_status;

	fdstdint = dup(0);
	fdstdout = dup(1);
	fd_out = open(av[4], O_WRONLY | O_TRUNC | O_CREAT);
	if (fd_out == -1)
		error("can't open fd_out", 1);
	dup2(fd_out, 1);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	result = ft_executate_command(av[3], env);
	close(fd_out);
	dup2(fdstdint, 0);
	dup2(fdstdout, 1);
	if (result == -1)
		return (-1);
	waitpid(pid, &exit_status, 0);
	return (0);
}

int	pipex(char **av, char **env)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		result;

	pid = 0;
	result = 0;
	if (pipe(pipe_fd) == -1)
		error ("pipe doesn't open", 1);
	pid = fork();
	if (pid == -1)
		error ("pid is wrong", 1);
	else if (pid == 0)
		result = ft_child(av, env, pipe_fd);
	else
		result = ft_parent(av, env, pipe_fd, pid);
	return (result);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (pipex(av, env) == -1)
		error ("pipex doesn't work", 1);
	return (0);
}
