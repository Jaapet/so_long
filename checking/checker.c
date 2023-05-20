/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:12:03 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/20 16:59:15 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_rect(t_instance *instance)
{
	int	i;

	i = 0;
	while (i < instance->height)
	{
		if (ft_strlen(instance->map[i]) != instance->width)
			throw_error();
		i++;
	}
}

static void	counter(int *count)
{
	if (count[0] != 1 || count[1] != 1)
		throw_error();
	if (count[2] == 0)
		throw_error();
}

static void	check_chars(t_instance *instance)
{
	int	spe_chars[3];
	int	i;
	int	j;

	spe_chars[0] = 0;
	spe_chars[1] = 0;
	spe_chars[2] = 0;
	i = 0;
	while (i < instance->height)
	{
		j = 0;
		while (j < instance->width)
		{
			if (instance->map[i][j] == 'P' || instance->map[i][j] == 'E')
				spe_chars[instance->map[i][j] % 2]++;
			else if (instance->map[i][j] == 'C')
				spe_chars[2]++;
			else if (instance->map[i][j] != '0' && instance->map[i][j] != '1')
				throw_error();
			j++;
		}
		i++;
	}
	counter(spe_chars);
}

static void	check_walls(t_instance *instance)
{
	int	i;
	int	j;

	i = 0;
	while (i < instance->height)
	{
		j = 0;
		while (j < instance->width)
		{
			if ((i == 0 || i == instance->height - 1 || j == 0
					|| j == instance->width - 1) && instance->map[i][j] != '1')
				throw_error();
			j++;
		}
		i++;
	}
}

void	check_map(t_instance *instance)
{
	check_rect(instance);
	check_chars(instance);
	check_walls(instance);
	check_path(instance);
}
