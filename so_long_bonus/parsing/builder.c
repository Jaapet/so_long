/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:25:57 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 15:41:24 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	*get_pos(t_instance *instance, char c)
{
	int	i;
	int	j;
	int	*pos;

	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (NULL);
	i = 0;
	while (i < instance->height)
	{
		j = 0;
		while (j < instance->width)
		{
			if (instance->map[i][j] == c)
			{
				pos[0] = i;
				pos[1] = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

t_instance	*build_instance(char *file)
{
	t_instance	*instance;

	instance = malloc(sizeof(t_instance));
	if (!instance)
		return (NULL);
	instance->height = get_height(file);
	if (!instance->height)
		throw_error("map is empty\n");
	instance->width = get_width(file);
	instance->map = parse_map(file, instance->height);
	if (!instance->map)
		return (NULL);
	instance->pos = get_pos(instance, 'P');
	instance->exit = get_pos(instance, 'E');
	instance->count = 0;
	instance->moves = 0;
	check_map(instance);
	return (instance);
}
