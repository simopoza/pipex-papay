/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:16:02 by mannahri          #+#    #+#             */
/*   Updated: 2022/02/18 01:22:52 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char *path[])
{
	char	**s2;
	char	*s;
	int		i;

	i = 0;
	if (!path)
		exit (1);
	while (path[i])
	{
		if (!ft_strncmp(path[i], "PATH=", 4))
		{
			s = ft_substr(path[i], 5, ft_strlen(path[i]));
			s2 = split_path(s, ':');
			free (s);
			return (s2);
		}
		i++;
	}
	return (NULL);
}

void	free_lmlawi(void	**mlawi, int i)
{
	while (mlawi[i])
	{
		free (mlawi[i]);
		i++;
	}
	free (mlawi);
}

void	inital(t_mypath *t, char *str, char *env[])
{
	t->i = -1;
	t->path_splited = find_path(env);
	t->path = split_path(str, ' ');
	t->help = t->path_splited;
}

char	**check_cmd(char *str, char *env[])
{
	t_mypath	*t;

	t = malloc(sizeof(t_mypath));
	if (!t)
		return (0);
	if (!t->path_splited)
		exit (0);
	inital(t, str, env);
	while (t->path_splited[++t->i])
	{
		t->path_splited[t->i] = ft_strjoin(t->path_splited[t->i], "/");
		t->r = ft_strjoin(t->path_splited[t->i], t->path[0]);
		if (!access(t->r, X_OK))
		{
			free (t->path[0]);
			t->path[0] = t->r;
			free_lmlawi((void **)t->help, ++t->i);
			free (t);
			return (t->path);
		}
		free (t->r);
	}
	free (t->path_splited);
	free (t);
	return (t->path);
}

// void	inital(char *str, char *env[])
// {
// 	t_mypath.i = -1;
// 	t_mypath.path_splited = find_path(env);
// 	t_mypath.path = split_path(str, ' ');
// 	t_mypath.help = t_mypath.path_splited;
// }

// char	**check_cmd(char *str, char *env[])
// {
// 	inital(str, env);
// 	if (!t_mypath.path_splited)
// 		exit (0);
// 	while (t_mypath.path_splited[++t_mypath.i])
// 	{
// 		t_mypath.path_splited[t_mypath.i] = \
// 		ft_strjoin(t_mypath.path_splited[t_mypath.i], "/");
// 		t_mypath.r = \
// 		ft_strjoin(t_mypath.path_splited[t_mypath.i], t_mypath.path[0]);
// 		if (!access(t_mypath.r, X_OK))
// 		{
// 			free (t_mypath.path[0]);
// 			t_mypath.path[0] = t_mypath.r;
// 			free_lmlawi((void **)t_mypath.help, ++t_mypath.i);
// 			return (t_mypath.path);
// 		}
// 		free (t_mypath.r);
// 	}
// 	free (t_mypath.path_splited);
// 	return (t_mypath.path);
// }
