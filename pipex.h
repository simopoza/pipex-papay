/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:47:49 by mannahri          #+#    #+#             */
/*   Updated: 2022/02/18 00:17:52 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipe{
	char	**path_splited;
	char	**path;
	char	**help;
	char	*r;
	int		i;
}	t_mypath;

void	free_lmlawi(void **mlawi, int i);
char	**split_path(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char	*s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	**check_cmd(char *str, char *env[]);
int		check_file(char *str);
int		make_file(char *str);
void	child2_process(char *av, char *a, char **env, int pfd[]);
void	child1_process(char *av, char *a, char **env, int pfd[]);
int		main(int ac, char *av[], char *env[]);

#endif