/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:32:04 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 15:32:03 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_height(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		throw_error("map file is not valid\n");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	get_width(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line[i])
		i++;
	close(fd);
	free(line);
	return (i);
}

char	**parse_map(char *file, int size)
{
	int		fd;
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (size)
	{
		map[i] = get_next_line(fd);
		i++;
		size--;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
