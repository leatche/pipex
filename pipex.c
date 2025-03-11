/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:23:11 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/11 00:59:18 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>


// int pipex(int ac, char **av, char **env)
// {
// 	pid_t	pid = 0;
// 	int		exit_status;
// 	char buffer[11];
// 	int read_ret;
// 	int pipe_fd[2];

// 	(void *)env;
// 	if (pipe(pipe_fd) == -1)
// 		return (-1);
// 	pid = fork();
// 	if (pid == -1)
// 		return (-1);
// 	if (pid) // Parent
// 	{
// 		int fdstdint = dup(0);
// 		int fdstdout = dup(1);
// 		int fd_in = open("./InputFile", O_RDONLY);

// 		if (fd_in == -1)
// 			return (-1);
// 		dup2(fd_in, 0);
// 		dup2(pipe_fd[1], 1);
// 		close(pipe_fd[0]);

// 		// Cat
// 		read_ret = read(0, buffer, 10);
// 		buffer[read_ret] = '\0';
// 		write(1, buffer, read_ret);
// 		// Fin de cat
		
// 		close(0);
// 		close(1);
// 		dup2(fdstdint, 0);
// 		dup2(fdstdout, 1);
// 		waitpid(pid, &exit_status, 0);
// 	}
// 	else // Child
// 	{
// 		int fdstdint = dup(0);
// 		int fdstdout = dup(1);
// 		int fd_out = open("./OutputFile", O_WRONLY | O_TRUNC);

// 		dup2(fd_out, 1);
// 		close(pipe_fd[1]);
// 		dup2(pipe_fd[0], 0);
// 		// Grep O_WRONLY | 
// 		read_ret = read(0, buffer, 10);
// 		buffer[read_ret] = '\0';
// 		write(1, buffer, read_ret);
// 		write(1, "\n", 1);
// 		// Fin de Grep

// 		close(0);
// 		close(1);
// 		dup2(fdstdint, 0);
// 		dup2(fdstdout, 1);
// 		close(fd_out);
// 		exit (42);
// 	}
// }

void ft_putstr(char *str)
{
	while (str && *str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_executate_command(char *av, char **env)
{
	char	*command;
	// char **command_av = ft_split(av, ' ');
	char *command_av[2] = {
		"/bin/ls",
		NULL
	};
	// char	*path;

	command = av;
	execve("/bin/cat", command_av, env);
	// path = get_path(command, env);
	
}

int	ft_parent(char **av, char **env, int pipe_fd[], int pid)
{
	int	fdstdint;
	int	fdstdout;
	int	fd_in;
	int	exit_status;

	fdstdint = dup(0);
	fdstdout = dup(1);
	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
		return (-1);
	dup2(fd_in, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	ft_executate_command(av[2], env);
	close(0);
	close(1);
	dup2(fdstdint, 0);
	dup2(fdstdout, 1);
	waitpid(pid, &exit_status, 0);
	printf("Child exited with: %d\n", exit_status);
}

int	ft_child(char **av, char **env, int pipe_fd[])
{
	int	fdstdint;
	int	fdstdout;
	int	fd_out;

	fdstdint = dup(0);
	fdstdout = dup(1);
	fd_out = open(av[4], O_WRONLY | O_TRUNC);
	if (fd_out == -1)
		exit(1);
	dup2(fd_out, 1);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	ft_executate_command(av[3], env);
	close(0);
	close(1);
	close(fd_out);
	exit(0);
}

int pipex(int ac, char **av, char **env)
{
	pid_t	pid;
	int		pipe_fd[2];

	(void *)env;
	pid = 0;
	if (pipe(pipe_fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid)
		ft_parent(av, env, pipe_fd, pid);
	else
		ft_child(av, env, pipe_fd);
}

int main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		ft_putstr(" il y a un problème d'arguments non ??\n");
		return (-1);
	}
	if (pipex(ac, av, env) == -1)
	{
		ft_putstr(" petite erreur non ?\n");
		return (-1);
	}
	return (0);
}