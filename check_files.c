/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:17:51 by mannahri          #+#    #+#             */
/*   Updated: 2022/02/17 03:32:01 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDWR, 644);
	if (fd < 0)
		perror("This file does not exist");
	return (fd);
}

int	make_file(char *str)
{
	int	fd;

	fd = open(str, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
		perror("Error creating file");
	return (fd);
}
