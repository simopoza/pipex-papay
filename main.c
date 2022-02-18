/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:17:13 by mannahri          #+#    #+#             */
/*   Updated: 2022/02/17 03:32:05 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *env[])
{
	int	pfd[2];
	int	p;

	if (ac != 5)
	{
		perror("to much arguments.");
		exit(1);
	}
	p = pipe(pfd);
	if (p == -1)
		exit(1);
	child1_process(av[2], av[1], env, pfd);
	child2_process(av[3], av[4], env, pfd);
	close (pfd[0]);
	close (pfd[1]);
	while (wait(NULL) != -1)
	{
	}
	system("leaks pipex");
	return (0);
}
