/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:19:18 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 15:38:05 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**copy_map(char **map, int height, int width)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			ft_free(copy, i + 1);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

int	is_valid_path(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] != '1' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	search(char **map, int i, int j, t_instance *instance)
{
	int	c;

	c = 0;
	if (map[i + 1][j] == '1' && map[i - 1][j] == '1'
		&& map[i][j + 1] == '1' && map[i][j - 1] == '1')
	{
		map[i][j] = '1';
		c += is_valid_path(map, instance->height, instance->width);
	}
	else
	{
		map[i][j] = '1';
		if (map[i + 1][j] != '1')
			c += search(map, i + 1, j, instance);
		if (map[i - 1][j] != '1')
			c += search(map, i - 1, j, instance);
		if (map[i][j + 1] != '1')
			c += search(map, i, j + 1, instance);
		if (map[i][j - 1] != '1')
			c += search(map, i, j - 1, instance);
	}
	return (c);
}

void	check_path(t_instance *instance)
{
	char	**copy;
	int		check;

	copy = copy_map(instance->map, instance->height, instance->width);
	if (!copy)
		return ;
	check = search(copy, instance->pos[0], instance->pos[1], instance);
	ft_free(copy, instance->height);
	if (!check)
		throw_error("player must reach every collectibles and exit\n");
}
